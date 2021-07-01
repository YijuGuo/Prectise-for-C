    #include <iostream>
    #include <algorithm>

    using namespace std;
    const int N = 1e5+10;
    int n;
    int q[N],tmp[N];
    void merge_sort(int q[],int l,int r)
    {
        if(l>=r) return;
        //中点
        int mid = (l+r)>>1 ;
        merge_sort(q,l,mid);
        merge_sort(q,mid+1,r);
        //k表示序列合并的时候，已经合并的数目
        //i表示左半边有序序列的起点
        //j表示右半边有序序列的起点
        int k = 0, i = l,j = mid + 1;
        
        while (i<=mid &&j<=r)
        {
            if(q[i]<=q[j])tmp[k++]=q[i++];
            else tmp[k++] =q[j++];
        }
        
        while(i<=mid) tmp[k++] = q[i++];
        while(j<=r) tmp[k++] = q[j++];

        //将临时数组中的有序序列存回q序列中
        for(i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
    }

    int main()
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&q[i]);
        merge_sort(q,0,n-1);
        for(int i=0;i<n;i++)printf("%d ",q[i]);
        return 0;
    }