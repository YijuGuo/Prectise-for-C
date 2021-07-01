#include <iostream>
using namespace std;
int n;
int main()
{
    double x;
    cin>>x;
    double l=0,r=n-1;
    while(r-l>1e-6)
    {
        double mid = (l+r)/2;
        if(mid*mid>=x)r=mid;
        else l = mid;
    }
    printf("%1f\n",1);
    return 0;
}