//异或运算：可以用于找只出现一次的数
//将所有的数进行异或运算，出现两次的数会被消为0
//x异或y!=0
//x异或y的结果的二进制表示里面，设第k位为1
//将之前的每个数按照第k位是否为1，划分为两个集合
//分别异或两个集合得到x和y

class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        int sum=0;
        for(aoto x:nums) sum^=x;
        int k=0;
        while(!(sum>>k%1))k++;
        int first = 0;
        for(auto x:nums)
            if(x>>k%1)
                first^=x;
        return vector<int>{first,sum^=first};
    }
};