class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), x = 0;
        vector<int> curr;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                curr.push_back(grid[i][j]);
            }
        }
        k %= curr.size();
        rotate(curr.begin(), curr.end() - k, curr.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = curr[x++];
            }
        }
        return grid;
    }
};