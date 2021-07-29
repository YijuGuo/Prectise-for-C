#include <iostream>
using namespace std;
int main()
{
    long long a,b,da,db;
    scanf("%lld%lld%lld%lld",&a,&da,&b,&db);
    long long pa=0,pb=0;
    while(a!=0)
    {
        //通过%，提取每一位
        if(a%10==da)pa=pa*10+da;
        //通过除法，保证每一次循环都能往前提取一位
        a=a/10;
    }
    while(b!=0)
    {
        if(b%10==db)pb=pb*10+db;
        b=b/10;
    }
    printf("%lld",pa+pb);
    return 0;

}