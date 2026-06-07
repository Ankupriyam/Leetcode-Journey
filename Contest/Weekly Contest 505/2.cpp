class Solution {
public:
    vector<string>ans;
    void f(int i,int total,int n,string&s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        s+='0';
        f(i+1,total,n,s);
        if(i<=total && (i==0||(s[i-1]!='1'))){
            s[s.size()-1]='1';
            f(i+1,total-i,n,s);
        }
        s.pop_back();
    }
    vector<string> generateValidStrings(int n, int k) {
        string s="";
        f(0,k,n,s);
        return ans;
        
    }
};