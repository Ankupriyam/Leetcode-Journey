class Solution {
public:
    bool isGood(vector<int>& nums) {
        int x=nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<x;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        return nums[nums.size()-1]==x;
    }
};