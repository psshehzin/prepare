// memoization
#include <iostream>
using namespace std;
int f[200];
int fibnocci(int n){
    if (n<2){
        f[n]=n;
        return n;
    }
    else{
        if (f[n-1] == -1){
            f[n-1] = fibnocci(n-1);
        }
        if (f[n-2] == -1){
            f[n-2] = fibnocci(n-2);
        }
        f[n] = f[n-2] + f[n-1];
        return f[n];
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<=200;i++){
        f[i]=-1;
    }
    int fact=fibnocci(n);
    printf("fibnocci calculated upto %d is %d\n", n,fact);
    return 0;
}