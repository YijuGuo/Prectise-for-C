#include <iostream>
using namespace std;
int main()
{
    int n;
    int step1=0;
    scanf("%d",&n);
    while(n!=1)
    {
        if(n%2==0)n/=2;
        else n =(3*n+1)/2;

     step1++;
    }
    printf("%d",step1);
    return 0;
}