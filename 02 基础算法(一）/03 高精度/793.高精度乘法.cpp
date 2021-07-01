#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//计算C=A*b 高精度整数乘以低精度整数
vector<int> mul(vector<int>&A,int b )
{
   vector<int> C;
   int t=0;
   //考虑到最后一位的进位的情况，因此for循环执行条件为i<A.size()||t
   for(int i=0;i<int(A.size())||t;i++)
   {
       if(i<int(A.size()))t+=A[i]*b;
       C.push_back(t%10);
       t/=10; //进位（整除10为进位）
   }
   return C;
}

int main()
{
    //因为字符串太长，使用字符串读入，并且存入数组
    string a;
    int b;
    vector<int> A;
    //读入字符串
    cin>>a>>b;
    //逆序将字符串存入数组
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    vector<int> C = mul(A,b);
    for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);

    return 0;
    
}

