//0-1背包问题
public int backPack(int[]A, int T)
{
    int i,j;
    int n= A.length;
    if(n == 0){
        return 0;
    }
    int []f =new int [T+1];
    f[0] = 1;
    for(int i=1;i<=T;++i)
    {
        f[i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        for(j=T;j>=0;--j){
            if(j>=A[i-1])
            {
                f[j]+=f[j-A[i-1]];
            }
        }
    }
}