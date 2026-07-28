class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int i = 0, j = n - 1;
        for (auto& it : mp) {
            int time = it.second / 2;
            while (time--) {
                s[i++] = it.first;
                s[j--] = it.first;
            }

        }
        return s;
    }
};