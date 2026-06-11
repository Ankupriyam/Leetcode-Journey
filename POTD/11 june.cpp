class Solution {
public:
#define ll long long
    ll MOD=1e9+7;
    ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    int f(int i, vector<vector<int>>& adj, vector<int>& vis) {
        int ans = 1;
        auto& v = adj[i];
        for (auto& x : v) {
            if (!vis[x]) {
                vis[x] = 1;
                ans = max(ans, 1 + f(x, adj, vis));
            }
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            edges[i][0]--, edges[i][1]--;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        vis[0] = 1;
        int depth = f(0, adj, vis);
        return power(2,depth-2);
    }
};