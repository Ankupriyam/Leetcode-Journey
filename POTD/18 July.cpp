class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1e9,maxi=0;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return gcd(mini,maxi);
    }
};