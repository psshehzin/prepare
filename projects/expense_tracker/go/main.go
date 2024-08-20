package main

import (
	"context"
	"log"
	"net/http"
	"time"

	"github.com/gin-contrib/cors"
	"github.com/gin-gonic/gin"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/mongo/readpref"
)

var client *mongo.Client

type Transaction struct {
	ID          string    `json:"id,omitempty" bson:"_id,omitempty"`
	Amount      float64   `json:"amount" bson:"amount"`
	Type        string    `json:"type" bson:"type"` // "in" or "out"
	Description string    `json:"description" bson:"description"`
	Date        time.Time `json:"date" bson:"date"`
}

func main() {
	router := gin.Default()

	// Enable CORS
	router.Use(cors.Default())

	// MongoDB connection
	ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
	defer cancel()

	clientOptions := options.Client().ApplyURI("mongodb://localhost:27017")
	var err error
	client, err = mongo.Connect(ctx, clientOptions)
	if err != nil {
		log.Fatal(err)
	}

	err = client.Ping(ctx, readpref.Primary())
	if err != nil {
		log.Fatal(err)
	}

	router.POST("/transactions", createTransaction)
	router.GET("/transactions", getTransactions)
	router.GET("/balance", getBalance)

	router.Run(":8080")
}

func createTransaction(c *gin.Context) {
	var transaction Transaction
	if err := c.ShouldBindJSON(&transaction); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}
	transaction.Date = time.Now()

	collection := client.Database("expenseDB").Collection("transactions")
	_, err := collection.InsertOne(context.TODO(), transaction)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to create transaction"})
		return
	}

	c.JSON(http.StatusOK, transaction)
}

func getTransactions(c *gin.Context) {
	var transactions []Transaction

	collection := client.Database("expenseDB").Collection("transactions")
	cursor, err := collection.Find(context.TODO(), bson.M{})
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to retrieve transactions"})
		return
	}
	defer cursor.Close(context.TODO())

	for cursor.Next(context.TODO()) {
		var transaction Transaction
		cursor.Decode(&transaction)
		transactions = append(transactions, transaction)
	}

	c.JSON(http.StatusOK, transactions)
}

func getBalance(c *gin.Context) {
	collection := client.Database("expenseDB").Collection("transactions")
	cursor, err := collection.Find(context.TODO(), bson.M{})
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to retrieve balance"})
		return
	}
	defer cursor.Close(context.TODO())

	balance := 0.0
	for cursor.Next(context.TODO()) {
		var transaction Transaction
		cursor.Decode(&transaction)
		if transaction.Type == "in" {
			balance += transaction.Amount
		} else if transaction.Type == "out" {
			balance -= transaction.Amount
		}
	}

	c.JSON(http.StatusOK, gin.H{"balance": balance})
}
