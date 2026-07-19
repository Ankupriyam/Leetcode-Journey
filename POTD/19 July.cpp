class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> mp;
        set<char> stt;
        for (char c : s)
            mp[c]++;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]--;
            if (stt.find(s[i]) != stt.end())
                continue;
            while (!st.empty() && mp[st.top()] >= 1 && st.top() > s[i]) {
                stt.erase(st.top());
                st.pop();
            }
            stt.insert(s[i]);
            st.push(s[i]);
        }
        string ans = "";
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};