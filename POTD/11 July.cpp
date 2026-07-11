class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int& nodes,int& edges) {
        vis[i] = 1;
        nodes++;
        edges += adj[i].size();
        for (auto x : adj[i]) {
            if (!vis[x]) {
                dfs(x, adj, vis,nodes, edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(0, 0));
        vector<int> vis(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            int nodes = 0;
            int degSum = 0;

            dfs(i, adj, vis, nodes, degSum);

            int actualEdges = degSum / 2;
            int requiredEdges = nodes * (nodes - 1) / 2;

            if (actualEdges == requiredEdges)
                ans++;
        }
        return ans;
    }
};