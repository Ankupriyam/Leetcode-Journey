class Solution {
public:
#define ll long long
    ll dp[20][11][2][2];
    ll f(ll i, int prev, ll small, int st, int k, string& s) {
        if (i == s.size()) {
            return st;
        }
        if (dp[i][prev + 1][small][st] != -1)
            return dp[i][prev + 1][small][st];
        ll ans = 0;
        ll curr = s[i] - '0';
        ll limit = small ? curr : 9;
        if (!st) {
            ans += f(i + 1, -1, small && (curr == 0), 0, k, s);
            for (int d = 1; d <= limit; d++) {
                ans += f(i + 1, d, small && (curr == d), 1, k, s);
            }
        } else {
            ll start = max(prev - k, 0);
            ll end = min(9, prev + k);
            for (int d = start; d <= min(end, limit); d++) {
                ans += f(i + 1, d, small && (curr == d), 1, k, s);
            }
        }
        return dp[i][prev + 1][small][st] = ans;
    }

    long long goodIntegers(long long l, long long r, int k) {
        l--;
        string s = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll ans = f(0, -1, 1, 0, k, s);
        s = to_string(l);
        memset(dp, -1, sizeof(dp));
        ans -= f(0, -1, 1, 0, k, s);
        return ans;
    }
};