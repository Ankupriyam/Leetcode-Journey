class Solution {
public:
    bool checkGoodInteger(int n) {
        int ans=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'0';
            if(curr>0)
            ans+=curr*(curr-1);
            if(ans>=50){
                return true;
            }
        }
        return false;
    }
};