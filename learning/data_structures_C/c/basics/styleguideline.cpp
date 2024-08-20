#include<stdio.h>
using namespace std;
class Rectangle
{
    private: 
        int length;
        int breadth;
    public: 
        Rectangle(int l, int b){
            length=l;
            breadth=b;
        }
        void area()
        {
            printf("Area: %d \n", length*breadth);
        }

        void updatelength(int l){
            length=l;
        }
};

int main(){
    Rectangle r(7,10);
    r.area();
    r.updatelength(10);
    r.area();
    return 0;
}
