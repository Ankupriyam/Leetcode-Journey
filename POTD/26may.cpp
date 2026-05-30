class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> freq(256, false);
        for (int i = 0; i < word.size(); i++) {
            freq[word[i]] = true;
        }
        int ans = 0;
        for (int i = 'A'; i <= 'Z'; i++) {
            if (freq[i] && freq[i + 'a' - 'A']) {
                ans++;
            }
        }
        return ans;
    }
};