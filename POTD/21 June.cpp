class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> mp;
        for (int i = 0; i < costs.size(); i++) {
            mp[costs[i]]++;
        }
        int ans = 0;
        for (auto& it : mp) {
            if (coins < it.first)
                break;
            while (coins >= it.first && it.second > 0) {
                coins-=it.first;
                it.second--;
                ans++;
            }
        }
        return ans;
    }
};