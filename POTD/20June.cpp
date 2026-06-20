class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& nums) {
        int m = nums.size();
        nums.push_back({1, 0});
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            int d = nums[i][0] - nums[i - 1][0];
            nums[i][1] = min(nums[i][1], nums[i - 1][1] + d);
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            int d = nums[i + 1][0] - nums[i][0];
            nums[i][1] = min(nums[i][1], nums[i + 1][1] + d);
        }
        int ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            int x1 = nums[i - 1][0];
            int h1 = nums[i - 1][1];

            int x2 = nums[i][0];
            int h2 = nums[i][1];

            int d = x2 - x1;

            ans = max(ans, (h1 + h2 + d) / 2);
        }
        int lastPos = nums.back()[0];
        int lastH = nums.back()[1];

        ans = max(ans, lastH + (n - lastPos));

        return ans;
    }
};