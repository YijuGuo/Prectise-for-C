/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。

如果是则返回true，否则返回false。

假设输入的数组的任意两个数字都互不相同。

样例
输入：[4, 8, 6, 12, 16, 14, 10]

输出：true

*/

//后序遍历：先遍历左子树，再遍历右子树，最后是root
//左子树的所有结点都比根结点小
//右子树的所有结点都比根结点大
//分别递归左子树和右子树
//[4, 8, 6, 12, 16, 14, 10]
//root:10 ,左子树：[4, 8, 6],右子树：[12, 16, 14]
//左子树： root:6 左：4 右8
class Solution {
public:

    //引入全局变量
    vector<int> seq;

    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;
        //讨论空树的情况
        if (seq.empty()) return true;
        //dfs递归，输入左右边界进行递归
        return dfs(0, seq.size() - 1);
    }

    bool dfs(int l, int r) {
        //如果序列为0，为合法的二叉搜索树，返回true
        if (l >= r) return true;
        //取root值进行比较
        int root = seq[r];
        //k从序列最左端开始对比
        int k = l;
        //遍历左子树的终结的位置，此时k为右子树的第一个元素
        while (k < r && seq[k] < root) k ++ ;
        //判断右子树的所有点是否都比根结点大，如果满足，则右子树合法
        for (int i = k; i < r; i ++ )
            if (seq[i] < root)
                return false; //右子树不合法
        return dfs(l, k - 1) && dfs(k, r - 1); //递归左子树和右子树
    }
};

class Solution {
public:

    vector<int> seq;
    bool verifySequenceOfBST(vector<int> sequence) {
        seq=sequence;
        if(!seq)return true;
        return dfs(0,seq.size()-1);
    }
    
    bool dfs(int l,int r)
    {
        if(l>=r)return true;
        int root = seq[r];
        int k=l;
        while(k<r&&seq[l]<root)k++;
        for(int i=k+1;i<r;i++)
            if(seq[i]<root)return false;
        return dfs(l,k-1)&& dfs(k,r-1);
    }

    
};