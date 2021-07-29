/*
本题核心：题目需要求的是成绩最好的学校
无需一开始就用数组把所有的输入记录进去
而是可以在输入的阶段，计算每一所学校的成绩总和
*/

#include<iostream>
using namespace std;
const int N = 1e5+10;
int school[N];
int sID,score;
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d",&sID,&score);
        school[sID]+=score;
    }
    int k=0;
    int maxscore = 0;
    for(int i =0;i<N;i++)
        if(school[i]>maxscore)
        {
            maxscore=school[i];
            k=i;
        }
    
    printf("%d %d",k,maxscore);

}