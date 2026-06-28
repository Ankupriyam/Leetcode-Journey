class Solution {
public:
#define ll long long
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums,
                                                int freeStart, int freeEnd) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans, res;
        int n = nums.size();
        for (auto& it : nums) {
            if (ans.empty() || (ll)it[0] > ans.back()[1] + 1) {
                ans.push_back(it);
            } else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            ll mini = ans[i][0], maxi = ans[i][1];
            if (maxi < freeStart || mini > freeEnd) {
                res.push_back({(int)mini, (int)maxi});
                continue;
            }
            if (mini < freeStart) {
                res.push_back({(int)mini, freeStart - 1});
            }
            if (maxi > freeEnd) {
                res.push_back({freeEnd + 1, (int)maxi});
                mini = 0, maxi = 0;
            }
        }

        return res;
    }
};