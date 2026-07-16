class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> curr;
        int x = 0, n = nums.size();
        long long ans = 0;
        ;
        for (int i = 0; i < nums.size(); i++) {
            x = max(x, nums[i]);
            curr.push_back(gcd(x, nums[i]));
        }
        sort(curr.begin(), curr.end());
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(curr[i], curr[n - i - 1]);
        }
        return ans;
    }
};