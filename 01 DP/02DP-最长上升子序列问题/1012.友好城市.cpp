#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 5050;

int n;
PII q[N];
int f[N];

int main()
{
    //输入
    scanf("%d",&n);
    for(int i =1; i<=n; i++) scanf("%d%d",&q[i].first,&q[i].second);
    //排序
    sort(q,q+n);
    int res = 0;
    for(int i = 1; i<=n; i++)
    {
        f[i]=1;
        for(int j=1; j<i;j++)
        {
            if(q[j].second<q[i].second)
                f[i] = max(f[i],f[j]+1);
                
        }
        res = max(res,f[i]);
    }
    printf("%d\n",res);
    return 0;
}