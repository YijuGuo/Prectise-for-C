#include <iostream>
#include <algorithm>
using namespace std;
const int N =1050;
int n;
int a[N],f[N];
int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)scanf("%d",&a[i]);
    //求解所有以a[i]结尾的严格单调上升的子序列的最长值
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            //限制条件：递增子序列 a[j]<a[i]
            if(a[j]<a[i])
            f[i]=max(f[i],f[j]+1);
        }
    }
    //最长子序列
    int res = 0;
    for(int i = 1; i<=n;i++)res = max(res,f[i]);
    printf("%d",res);
    return 0;
    
}