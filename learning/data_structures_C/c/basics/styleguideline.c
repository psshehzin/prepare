#include<stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b){
    r->length=l;
    r->breadth=b;
}
void area(struct Rectangle r)
{
    printf("Area: %d \n", r.length*r.breadth);
}

void updatelength(struct Rectangle *r, int l){
    r->length=l;
}

void main(){
    struct Rectangle r;
    initialize(&r,5,10);
    area(r);
    updatelength(&r, 10);
    area(r);
}