class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[high]==nums[mid] && nums[low]==nums[mid]){
                low++,high--;
                ans=min(ans,nums[mid]);
            }
            else if(nums[high]>=nums[mid]){
                ans=min(ans,nums[mid]);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};