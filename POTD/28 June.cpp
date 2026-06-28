class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), last = 1;
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            arr[i] = min(last + 1, arr[i]);
            last = arr[i];
        }
        return last;
    }
};