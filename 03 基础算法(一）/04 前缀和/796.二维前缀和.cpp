#include <iostream>
using namespace std;
const int N = 1010;
const int M = 1010;

int a[N][M];
int s[N][M];
int n,m,q;

int main()
{
    //输入
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    //构造数组求前缀和
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    //q的询问
    while(q--)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        //计算部分和
        printf("%d\n",s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);   
    }
    return 0;
}