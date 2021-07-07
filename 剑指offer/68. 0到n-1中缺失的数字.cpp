//二分的思想
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        //判断边界
        if(nums.empty())return 0;
        //左右边界是数组的范围
        int l=0,r=nums.size()-1;
        //二分找到中间边界的位置
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(nums[mid]!=mid)r=mid;
            else l=mid+1;
        }
        //特判，如果0～n-1均无缺失，那么缺失的是n
        if(nums[r]==r)r++;
        return r;
    }
};