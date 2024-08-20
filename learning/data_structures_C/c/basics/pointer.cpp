#include <iostream>
using namespace std;
// star for function returing pointer
int * array_return(int siz){
    // in c++ there is a keyword new for doing the allocation and for elting we have delete keyword 
    int *a = (int *)malloc(siz*sizeof(int));
    for(int i=0;i<siz;i++){
        a[i]=i;
    }
    return a;
}
int main() 
{
    int *p;
    p = array_return(5);
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl
        ;
    }
    free(p);
} // namespace std;
