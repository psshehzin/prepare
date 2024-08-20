// taylor series e^x = 1 +x + x^2/2! +x^3/3! ......+x^n/n^!
#include <iostream>
using namespace std;

float taylor(float x,float n){
    static float m=1;
    static float d =1;
    float val;
    if(n==0){
        return 1;
    }
    else{
        val = taylor(x, n-1);
        m = m*x;
        d = d*n;
        return val + m/d;
    }
}
int main(){
    float m, n;
    cout<<"Enter the power of e: \n";
    cin>>m;
    cout<<"Enter n in taylor more the better: \n";
    cin>>n;
    float power=taylor(m, n);
    printf("value of e to the power %f calculated via taylor upto  %f is %f \n",m,n,power);
    return 0;
}