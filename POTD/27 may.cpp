class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int> lastlower(26, -1), firstupper(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a') {
                lastlower[word[i] - 'a'] = i;
            } else {
                if (firstupper[word[i] - 'A'] == -1) {
                    firstupper[word[i] - 'A'] = i;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (firstupper[i] != -1 && lastlower[i] != -1 &&
                lastlower[i] < firstupper[i]) {
                ans++;
            }
        }
        return ans;
    }
};