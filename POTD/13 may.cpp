class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int pairs = n / 2;

        unordered_map<int, int> exact;
        vector<int> minimum, maximum;
        int i = 0, j = n - 1;
        while (i < j) {
            int a = nums[i], b = nums[j];
            exact[a + b]++;
            minimum.push_back(min(a, b) + 1);
            maximum.push_back(max(a, b) + limit);
            i++;
            j--;
        }
        sort(minimum.begin(), minimum.end());
        sort(maximum.begin(), maximum.end());
        int ans = INT_MAX;
        for (int target = 2; target <= 2 * limit; target++) {
            int zeroMoves = exact[target];
            int leftBad =
                minimum.end() - upper_bound(minimum.begin(), minimum.end(), target);
            int rightBad =
                lower_bound(maximum.begin(), maximum.end(), target) - maximum.begin();
            int twoMoves = leftBad + rightBad;
            int oneMove = pairs - zeroMoves - twoMoves;
            ans = min(ans, 2 * twoMoves + oneMove);
        }

        return ans;
    }
};