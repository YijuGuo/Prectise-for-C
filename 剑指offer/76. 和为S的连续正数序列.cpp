/*
输入一个正数 S，打印出所有和为 S 的连续正数序列（至少含有两个数）。

例如输入 15，由于 1+2+3+4+5=4+5+6=7+8=15，所以结果打印出 3 个连续序列 1∼5、4∼6 和 7∼8。

样例
输入：15

输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/
//i往后移动的时候，j必然也往后移动
//通过双指针算法，将其优化为O(n)
//正整数序列
class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        //遍历
        for(int i=1,j=1,s=1;i<=sum;i++)
        {
            //求解满足s=sum的时候的j的位置
            while(s<sum)j++,s+=j;
            if(s==sum && j>i)
            {
                vector<int> line;
                //将从i到j的数push入vector中
                for(int k=i;k<=j;k++) line.push_back(k);
                //将vector push入res中存储
                //res中存储的为vector向量
                res.push_back(line);
            }
            s-=i;
        }
        return res;
    }
};