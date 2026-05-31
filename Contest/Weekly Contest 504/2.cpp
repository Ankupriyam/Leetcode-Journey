class Solution {
public:
#define ll long long
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int ans = 0, mini = 1e9;
        unordered_map<int, int> mp;
        int n = items.size();
        for (int i = 0; i < n; i++) {
            mp[items[i][0]]++;
            mini = min(mini, items[i][1]);
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            ll total = 0;
            for (ll j = items[i][0]; j <= 1e5; j += items[i][0]) {
                if (mp.find(j) != mp.end()) {
                    total += mp[j];
                }
            }
            v.push_back(total);
        }
        vector<int> dp(budget + 1, -1);
        dp[0]=0;
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int w = budget; w >= p; w--) {
                if (dp[w - p] != -1) {
                    dp[w] = max(dp[w], dp[w - p] + v[i]);
                }
            }
        }
        for (int w = 0; w <= budget; w++) {
            if (dp[w] != -1) {
                ans = max(ans, dp[w] + (budget - w) / (mini));
            }
        }
        return ans;
    }
};