class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<bool> vis(n, false);
        vis[0] = true;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1) return steps;

            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            if (!vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            for (int next : mp[arr[idx]]) {
                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, steps + 1});
                }
            }

            mp[arr[idx]].clear();
        }

        return -1;
    }
};