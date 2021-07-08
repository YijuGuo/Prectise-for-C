//二分问题
class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        if(nums.empty())return 0;
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(nums[mid]-mid>=0)r=mid;
            else l=mid+1;
        }
        if(nums[r]-r==0)return r;
        return -1;
    }
};