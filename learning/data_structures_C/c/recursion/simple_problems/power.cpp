#include <iostream>
using namespace std;

int power_recurse(int m,int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power_recurse(m*m,n/2);
    }
    else{
        return m*power_recurse(m*m,(n-1)/2);
    }
}
int main(){
    int m, n;
    cout<<"Enter the number: \n";
    cin>>m;
    cout<<"Enter power: \n";
    cin>>n;
    int power=power_recurse(m, n);
    printf("%d to the power %d is %d \n",m,n,power);
    return 0;
}