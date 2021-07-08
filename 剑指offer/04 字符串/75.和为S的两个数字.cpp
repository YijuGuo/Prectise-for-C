//暴力解法
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
             if(nums[i]+nums[j]==target)
             return vector<int>{nums[i],nums[j]};

        }
    }
}

//哈希表的解法
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash;//创建哈希表
        for (int i = 0; i < nums.size(); ++i) {
            if(hash[target - nums[i]] == 0)//如果哈希表中没有target - nums[i]
                hash[nums[i]]++;//nums[i]出现次数加1
            else//如果哈希表中有target - nums[i]
                return {nums[i], target - nums[i]};//返回答案
        }
        return {};

    }
};