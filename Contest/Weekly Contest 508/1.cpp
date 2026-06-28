class Solution {
public:
#define ll long long
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long total = 0;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < min(n, k); i++) {
            if(mul>0){
                total+=(ll)mul*nums[i];
            }else{
                total+=nums[i];
            }
            mul--;
        }
        return total;
    }
};