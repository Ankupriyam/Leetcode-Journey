class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0;
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]++;
            ans=max(ans,mp.rbegin()->first+nums[i]);
        }
        return ans;
    }
};