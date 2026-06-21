class Solution {
public:
#define ll __int128
    ll f(int i, vector<vector<ll>>& adj, vector<int>& baseTime) {
        ll ans = baseTime[i];
        ll mini = 1e17, maxi = -1;
        for (auto& x : adj[i]) {
            ll curr = f(x, adj, baseTime);
            maxi = max(maxi, curr);
            mini = min(mini, curr);
        }
        if (maxi == -1)
            return ans;
        ll can = maxi - mini;
        return ans + can + maxi;
    }
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        vector<vector<ll>> adj(n, vector<ll>(0, 0));
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        long long ans = f(0, adj, baseTime);
        return ans;
    }
};