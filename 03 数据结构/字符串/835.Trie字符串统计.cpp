#include <iostream>
using namespace std;
const int N = 1e5+10;
//son[][]存储每个点的儿子
//cnt以当前结点结尾的单词有多少个
//idx：当前使用的下标；下标是0的点，既是根结点，又是空结点
int son[N][26],cnt[N],idx;
char str[N];
//插入操作
void insert(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
//返回字符串出现的次数
int query(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u = str[i]-'a';
        if(!son[p][u])return 0;
         p=son[p][u];
    }
    return cnt[p]; 
}

int main()
{
    int n;
    scanf("%d",&n);
    while(--n)
    {
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I')insert(str);
        else printf("%d \n",query(str));
    }
    return 0;
}
