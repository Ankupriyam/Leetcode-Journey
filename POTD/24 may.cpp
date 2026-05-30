class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp, int n, int d) {
        if (dp[i] != -1)
            return dp[i];
        int best = 1;
        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
            if (nums[nxt] >= nums[i])
                break;
            best = max(best, 1 + f(nxt, nums, dp, n, d));
        }
        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
            if (nums[nxt] >= nums[i])
                break;

            best = max(best, 1 + f(nxt, nums, dp, n, d));
        }
        return dp[i] = best;
    }
    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, f(i, nums, dp, n, d));
        }

        return ans;
    }
};