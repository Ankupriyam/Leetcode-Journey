class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string x1="",x2="";
        for(int i=0;i<n;i++){
            x1.push_back('.');
        }
        for(int i=0;i<n-1;i++){
            x2.push_back('#');
        }
        x2.push_back('.');
        vector<string>ans;
        ans.push_back(x1);
        for(int i=0;i<m-1;i++){
            ans.push_back(x2);
        }
        return ans;
    }
};