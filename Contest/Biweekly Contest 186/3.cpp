class Solution {
public:
    int minOperations(string s1, string s2) {
        if(s1=="1" && s2=="0") return -1;
        int n=s1.size();
        vector<bool> pb(n);
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) pb[i]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!pb[i]) continue;
            if(s1[i]=='0') ans++;
            else{
                if(i+1<n && s1[i+1]=='1' && pb[i+1]){
                    ans++;
                    i++;
                }
                else{
                    ans+=2;
                }
            }
        }
        return ans;
    }
};