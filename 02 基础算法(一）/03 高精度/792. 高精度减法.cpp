#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//判断是否有A>=B
bool cmp(vector<int>&A,vector<int>&B)
{
    //判断A和Bsize，如果size更大，则更大
    if(int(A.size())!=int(B.size())) return A.size()>B.size();
    //size相同时，从高位一个一个进行对比
    //如果A[i]不等于B[i]时，二者进行对比
    for(int i=int(A.size())-1;i>=0;i--)
    {
        if(A[i]!=B[i]) return A[i]>B[i];
    }
    return true;
}


//计算A-B
vector<int> sub(vector<int>&A,vector<int>&B )
{
   vector<int> C;
   for(int i =0,t=0;i<int(A.size());i++)
   {
       //减去借位
       t=A[i]-t;
       if(i<int(B.size()))t-=B[i];
       // t大于0，则为t本身
       // t小于0，则需要让t+10
       // (t+10)%10，即综合考虑上述两种情况，如果t大于10,则10被抵消
       C.push_back((t+10)%10);
       if(t<0) t=1;
       else t=0;
   }
   //减法需要考虑去掉前面的0，例如003，需要保留3，去掉0
   //通过循环，当C的size大于1，并且C.back()的值为0的时候，需要pop
   while(C.size()>1&&C.back()==0)C.pop_back();
   return C;
}


int main()
{
    //因为字符串太长，使用字符串读入，并且存入数组
    string a,b;
    vector<int> A,B;
    //读入字符串
    cin>>a>>b;
    //逆序将字符串存入数组
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    if(cmp(A,B))
    {
        vector<int> C = sub(A,B);
        for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    else
    {
        vector<int> C = sub(B,A);
        printf("-");
        for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    return 0;
    
}

