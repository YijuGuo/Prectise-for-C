#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1050;
int a[N];
int f[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++) scanf("%d",&a[i]);
    int res = 0;
    for(int i =1;i<=n;i++)
    {
        f[i]=a[i];
        for(int j=1;j<=i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+a[i]);
                //做错的地方f[j]+a[i]，而不是a[j]
        res = max(res,f[i]);
    }
    printf("%d\n",res);
    
    return 0;
}