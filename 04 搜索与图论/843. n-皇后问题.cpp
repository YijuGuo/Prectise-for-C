
#include <iostream>
using namespace std;
//对角线的数目为2*n-1，因此N开2*10
const int N = 20; 
int n;
char g[N][N];

//同一列、正对角线、反对角线
bool col[N],dg[N],udg[N];

void dfs(int u)
{
    //枚举结束，输出
    if(u==n)
    {
        for(int i=0;i<n;i++)puts(g[i]);
        puts(".");
        return;
    }
    //从前往后枚举，第u行皇后应该放在哪一列
    for(int i = 0;i<n;i++)
    {
        //对角线的截距
        //y=x+b, b=y-x+n (加偏移量，防止为负数)
        //y=-x+b, b=y+x
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i])
        {
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
    }
}

int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j] = '.';
    
    dfs(0);
    return 0;
    
}