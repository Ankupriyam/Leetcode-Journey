class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, 0), l(n, 0), ans(n);
        for (int i = n - 1; i > 0; i--) {
            r[i - 1] = nums[i] + r[i];
        }
        for (int i = 0; i < n - 1; i++) {
            l[i + 1] = nums[i] + l[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = abs(l[i] - r[i]);
        }
        return ans;
    }
};