#include <iostream>
using namespace std;
int cache[200];
int fact(int n){
    if (cache[n] != -1){
        printf("used cache for %d factorial\n", n);
        return cache[n];
    }
    else{
        printf("computed for %d factorial\n", n);
        if (n<=1){
            cache[1]=1;
            return(cache[1]);
        }
        else{
            cache[n]=n*fact(n-1);
            return cache[n];
        }
    }
}
int comb(int n, int r){
    int c= fact(n)/fact(r)*fact(n-r);
    return c;
}

int main(){
    int m,n;
    for(int i=0;i<200;i++){
        cache[i]=-1;
    }
    cout<<"Enter the number of items(n): \n";
    cin>>m;
    cout<<"Enter combination to be made of: \n";
    cin>>n;
    printf("%d %d %d %d %d",fact(5),fact(4),fact(3),fact(2),fact(1));
    printf("comb of %dc%d is %d", m,n,comb(m,n));
    return 0;
}