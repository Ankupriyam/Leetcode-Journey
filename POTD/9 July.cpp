class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> arr(n, 1);
        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                curr++;
            arr[i] = curr;
        }
        vector<bool> ans;
        for (auto it : queries) {
            if (arr[it[0]] == arr[it[1]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};