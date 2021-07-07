//位运算：每一位单独做位运算（好处）
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        //目的：统计x的哪些位是1
        //基本思路：状态机
        for(auto x:nums)
        {
            ones = (ones^x)&-twos;
            twos = ()
        }   
    }

};