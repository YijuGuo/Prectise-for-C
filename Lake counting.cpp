/*
 题目描述：有一个大小为M*N的园子，雨后起了积水。八连通的积水被认为是连接在一起的。
 请求出园子里总共有多少水洼.要求，分别输入M，N，以及园子的积水情况。M，N<=100。
 （八连通只的是下图中相对于'7'的'0'的位置，'7'表示积水，'0表示没有积水）
 3 3
 
 000
 070
 000

 输入样例：
 10 12
 700000000770
 077700000777
 000077000770
 000000000770
 000000000700
 007000000700
 070700000770
 707070000070
 070700000070
 007000000070
 输出样例：
 3
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void dfs(int i, int j)
{
    //将遍历到的位置置为0，则后面深度搜索的时候，不会重复搜索
    field[i][j]==0;

    // 通过循环遍历8个方向
    for (int dx = -1; dx <=1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = i+dx;
            int ny = j+dy;
            if (nx>=0&&nx<N&&ny>=0&&ny<M&&field[nx][ny]==7)
            {
                dfs(nx,ny);
            }   
        }    
    }
    return 0;

}


int main()
{
    int N,M;
    string temp;
    scanf("%d %d",&N,&M);

    int temp_number;
    int field[N][M];

    for(int i = 0;i<N;i++)
    {
     cin>>temp;
     for(int j = 0;j<M;j++)
       {
              temp_number = temp[j]-'0';
              field[i][j] = temp_number;
       }
    }

    //记录深度搜索的次数
      int res;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            //对field随机遍历，寻找水洼“7”，并以此为起点做深度搜索
            if (field[i][j]== 7)
            {
                //深度搜索
                dfs(i,j);
                res++;
            }    
        }
        
    }
    printf("%d",res);

    return 0;
}
