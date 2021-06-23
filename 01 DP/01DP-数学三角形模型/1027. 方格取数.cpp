
//破题点：只有当两条路线横纵坐标相等的时候，才有可能重合

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;
int n;
int w[N][N];
int f[N*2][N][N];

int main()
{
  scanf("%d",&n);
  int a,b,c;
  //通过cin的方式输入数组，并且进行赋值
  while(cin>>a>>b>>c,a||b||c)w[a][b]=c;
  //
  for (int k = 2; k<=n+n; k++)
    for (int i1 = 1; i1 <= n; i1++ )
        for (int i2 =1; i2 <=n; i2++)
        {
            int j1 = k - i1, j2 = k -i2;
            //限制j1和j2的大小
            if(j1>=1&&j1<=n&&j2>=1&&j2<=n)
            {
                //重合，如果k相同，并且i1和i2相等，则重合，二选一
                int t = w[i1][j1];
                //不重合的情况
                if(i1!=i2) t+=w[i2][j2];
                f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1-1][i2-1]+t);
                f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1-1][i2]+t);
                f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1][i2-1]+t);
                f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1][i2]+t);
                /*改进
                int &x = f[k][i1][i2];
                x = max(x,f[k-1][i1-1][i2-1]+t);
                x = max(x,f[k-1][i1-1][i2]+t);
                x = max(x,f[k-1][i1][i2-1]+t);
                x = max(x,f[k-1][i1][i2]+t);
                */
            }
        }

    printf("%d\n",f[n+n][n][n]);
    return 0;
}