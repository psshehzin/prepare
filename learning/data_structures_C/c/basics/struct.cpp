#include<iostream>
struct rect{
    int length;
    int breadth;
};
using namespace std;
int main(){
    struct rect recata={2,5};
    cout<<recata.length*recata.breadth;
    return 0;
}
