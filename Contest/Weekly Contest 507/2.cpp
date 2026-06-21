class Solution {
public:
#define ll long long
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];

                int rem = sum % 10;
                if (rem != x)
                    continue;
                ll sum2 = sum;
                while (sum2 != 0) {
                    rem = sum2 % 10;
                    sum2 /= 10;
                }
                if(rem!=x){
                    continue;
                }
                ans++;
            }
        }
        return ans;
    }
};