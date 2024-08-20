#include <iostream>
using namespace std;

int sum_recurse(int n){
    if(n>0){
        return n+sum_recurse(n-1);
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int sum=sum_recurse(n);
    printf("sum of first %d natural numbers is %d \n", n,sum);
    return 0;
}