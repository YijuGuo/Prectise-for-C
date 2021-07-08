/*
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 n。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7
输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/

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
            //位置u存入数值i
            path[u]=i;
            //进入下一层递归之前，修改状态
            //st[i]表示i已被使用
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