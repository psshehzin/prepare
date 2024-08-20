//  e^x =1+x[1+ x/2[1+x/3[1+x/4]....]
// taylor series e^x = 1 +x + x^2/2! +x^3/3! ......+x^n/n^!
#include <iostream>
using namespace std;

float taylor(int x,int n){
    static float s=1;
    if(n==0){
        return s;
    }
    s = 1+x*s/n;
    return taylor(x, n-1);
}
int main(){
    int m, n;
    cout<<"Enter the power of e: \n";
    cin>>m;
    cout<<"Enter n in taylor more the better: \n";
    cin>>n;
    float power=taylor(m, n);
    printf("value of e to the power %d calculated via taylor upto  %d is %f \n",m,n,power);
    return 0;
}