#include <iostream>
using namespace std;

int fact_recurse(int n){
    if(n!=1){
        return n*fact_recurse(n-1);
    }
    else{
        return 1;
    }
}
int main(){
    int n;
    cin>>n;
    int fact=fact_recurse(n);
    printf("factorial of %d is %d \n", n,fact);
    return 0;
}