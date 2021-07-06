#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10,M=1e6+10;
int n,m;
char p[N],s[M];
int ne[N];

int main()
{
    /*cin >> n;
    for(int i=1;i<=n;i++)cin>>p[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>s[i];*/
    cin>>n>>(p+1)>>m>>(s+1);
    //求Next数组的过程
    for(int i=2,j=0;i<=n;i++)
    {
        //不匹配，不断回退
        while(j&&p[i]!=p[j+1])j=ne[j];
        //匹配，则j++
        if(p[i]==p[j+1])j++;
        //Next数组记录模式串位置i对应的最长公共前后缀的长度
        ne[i]=j;
    }

    //KMP匹配的过程
    for(int i=1,j=0;i<=m;i++)
    {
        //匹配不成功，j回退
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        //如果匹配成功
        if(j==n)
        {
            //输出起始位置的长度
            printf("%d\n",i-n);
            for(int i=1;i<=n;i++)printf("%d ",ne[i]);
            //匹配成功，往前回退，求解是否有新的匹配字符串
            j=ne[j];
        }
    }
    return 0;
}