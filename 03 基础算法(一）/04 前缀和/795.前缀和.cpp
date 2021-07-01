#include <iostream>
using namespace std;
const int N = 1e5+10;
int n,m;
int a[N],s[N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    while(m--)
    {
        int l,r,sum;
        scanf("%d%d",&l,&r);
        sum = s[r]-s[l];
        printf("%d\n",sum);
    }
    
    return 0;
}