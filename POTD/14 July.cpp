class Solution {
public:
#define ll long long
    ll mod = 1e9 + 7;
    int dp[205][205][205];
    ll f(int i, int x, int y, vector<int>& nums) {
        if (i == nums.size())
            return 0;
        if (dp[i][x][y] != -1)
            return dp[i][x][y];
        ll ans = f(i + 1, x, y, nums) % mod, a = gcd(x, nums[i]),
           b = gcd(y, nums[i]);
        ans = (ans + (a == y) + f(i + 1, a, y, nums)) % mod;
        ans = (ans + (b == x) + f(i + 1, x, b, nums)) % mod;
        return dp[i][x][y] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, nums);
    }
};