class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            long long sum=0;
            for(int j=0;j<words[i].size();j++){
                sum+=weights[words[i][j]-'a'];
            }
            sum=sum%26;
            ans.push_back(char('z'-sum));
        }
        return ans;
    }
};