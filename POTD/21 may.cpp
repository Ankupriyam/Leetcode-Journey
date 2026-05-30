class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        for (int i = 0; i < arr1.size(); i++) {
            int x = arr1[i];
            while (x != 0) {
                st.insert(x);
                x /= 10;
            }
        }
        int ans=0;
        for (int i = 0; i < arr2.size(); i++) {
            int x = arr2[i];
            while (x != 0 && x>ans) {
                if(st.find(x)!=st.end()){
                    ans=max(ans,x);
                }
                x/=10;
            }
        }
        if(ans==0)return 0;
        return to_string(ans).size();
    }
};