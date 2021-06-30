#include <iostream>
#include <algorithm>
using namespace std;
const int N =3010;
int n;
int a[N],b[N];
int g[N][N];
int f[N][N];

int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j] = f[i-1][j];
            for(int k=1;k<=j;k++)
                if(b[k]<b[j])
                    f[i][j]=max(f[i][j],f[i][k]+1);
        }
    }
    int res = 0;
    for(int i=0;i<=n;i++) res = max(res,f[n][i]);
    printf("%d\n",res);
    return 0;
}
