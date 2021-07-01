#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int> &A :加引用的原因是因为，通过引用数组不被copy，效率增加
vector<int> add(vector<int>&A,vector<int>&B )
{
    vector<int> C;
    int t=0;//上一位的进位
    for(int i=0;i<int(A.size())||i<int(B.size());i++)
    {
        if(i<int(A.size()))t+=A[i];
        if(i<int(B.size()))t+=B[i]; 
        //t里面存的为A[i]+B[i]+上一位的进位
        C.push_back(t%10); //C内存储的为余数
        t/=10;//进位
    }
    if(t)C.push_back(1);
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
    vector<int> C = add(A,B);
    for(int i =C.size()-1;i>=0;i--)printf("%d ",C[i]);
    return 0;
    
}

