#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//计算C=A/b 高精度整数除以低精度整数
vector<int> div(vector<int>&A,int b,int &r )
{
   vector<int> C;
   r=0;
   //考虑到最后一位的进位的情况，因此for循环执行条件为i<A.size()||t
   for(int i=int(A.size())-1;i>=0;i--)
   {
       r = r*10+A[i];
       C.push_back(r/b);
       r%=b;
   }
   //C最开始得到的是最高位
   reverse(C.begin(),C.end());
   //消除前导0
   while(C.size()>1&&C.back()==0)C.pop_back();
   return C;
}

int main()
{
    //因为字符串太长，使用字符串读入，并且存入数组
    string a;
    int b;
    int r;
    vector<int> A;
    //读入字符串
    cin>>a>>b;
    //逆序将字符串存入数组
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    vector<int> C = div(A,b,r);
    for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);
    cout<<endl<<r<<endl;

    return 0;
    
}

