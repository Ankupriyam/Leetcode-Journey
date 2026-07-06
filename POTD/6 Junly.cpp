class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }
                 return a[1] > b[1];
             });
        int maxi = intervals[0][1];
        int n = intervals.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            if (maxi >= intervals[i][1]) {
                ans++;
            }
            maxi = max(maxi, intervals[i][1]);
        }
        return n-ans;
    }
};