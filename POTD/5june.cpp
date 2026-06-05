class Solution {
#define ll long long
    string s;
    map<tuple<int, int, int, int, int, int>, pair<ll, ll>> mp;
    pair<ll, ll> dfs(int i, int slast, int last, int tight, int started, int len) {
        if (i == s.size())
            return {1, 0};
        auto key = tuple(i, slast, last, tight, started, len);
        if (mp.count(key))
            return mp[key];
        ll cnt = 0, wav = 0;
        for (int d = 0; d <= (tight ? s[i] - '0' : 9); d++) {
            auto [c, w] = dfs(i + 1, last, d, tight && d == s[i] - '0', started || d,(started || d) ? len + 1 : 0);

            if (len > 1 && ((slast < last && last > d) || (slast > last && last < d)))
                w += c;

            cnt += c;
            wav += w;
        }
        return mp[key] = {cnt, wav};
    }

    ll solve(ll n) {
        s = to_string(n);
        mp.clear();
        return dfs(0, 0, 0, 1, 0, 0).second;
    }

public:
    long long totalWaviness(long long l, long long r) {
        return solve(r) - solve(l - 1);
    }
};