/*
一个商人穿过一个N×N的正方形的网格，去参加一个非常重要的商务活动。

他要从网格的左上角进，右下角出。

每穿越中间1个小方格，都要花费1个单位时间。

商人必须在(2N-1)个单位时间穿越出去
//不能走回头路，等价于摘花生的题

而在经过中间的每个小方格时，都需要缴纳一定的费用。

这个商人期望在规定时间内用最少费用穿越出去。

请问至少需要多少费用？

注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。

输入格式
第一行是一个整数，表示正方形的宽度N。

后面N行，每行N个不大于100的整数，为网格上每个小方格的费用。

输出格式
输出一个整数，表示至少需要的费用。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 110, INF = 1e9;
int n;
int w[N][N];
int f[N][N];

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        for(int j=1;j<=n;j++)
        scanf("%d",&w[i][j]);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j<= n; j++)
            //处理边界问题:第一行和第一列需要进行特判
            if(i==1&&j==1)f[i][j]=w[i][j];
            else{
                f[i][j] = INF;
                if(i>1)f[i][j]=min(f[i][j],f[i-1][j]+w[i][j]);
                if(j>1)f[i][j]=min(f[i][j],f[i][j-1]+w[i][j]); 
            }
        
    printf("%d",f[n][n]);
    return 0;
}