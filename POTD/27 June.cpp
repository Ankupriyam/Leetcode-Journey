class Solution {
public:
#define ll long long
    ll f(ll curr, unordered_map<ll, int>& mp) {
        if (curr == 1) {
            if (mp[1] % 2 == 0)
                return mp[1] - 1;
            return mp[1];
        }
        if (mp[curr] > 1 && mp.find(curr * curr) != mp.end()) {
            return 2 + f(curr * curr, mp);
        }
        mp[curr] = 0;
        return 1;
    }
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        ll ans = 1;
        for (auto& it : mp) {
            if (it.second > 0)
                ans = max(ans, f(it.first, mp));
        }
        return ans;
    }
};