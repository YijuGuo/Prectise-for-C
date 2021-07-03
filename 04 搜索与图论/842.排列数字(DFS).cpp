#include <iostream>
using namespace std;
//数据范围
const int N =10;
//输入的数据
int n;
//全局数组：存储路径path
int path[N];
//标记数据是否已经被使用
bool st[N];

void dfs(int u)
{
    //u=0时，根节点
    //u=1是看第一个位置，u=2是看第二个位置，以此类推
    //u=n时，为叶子节点，说明所有位置均已填满，此时搜索结束
    if(u==n)
    {
        for(int i=0;i<n;i++)printf("%d ",path[i]);
        //每一个方案输出空行
        puts(" ");
        return;
    }
    //u<n时，枚举i=1~3
    for(int i=1;i<=n;i++)
    {
        //状态未被使用
        if(!st[i])
        {
            path[u]=i;
            //进入下一层递归之前，修改状态
            st[i]=true;
            //递归
            dfs(u+1);
            //从递归中出来之后，需要恢复（恢复st[i])
            //由于path[u]会被不断地覆盖，path[u]无需恢复为0
            //path[u]=0;
            st[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}