class Solution {
public:
    bool f(string&s,string &t){
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j])i++;
            j++;
        }
        return i==s.size();
    }
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(n>m)return false;
        if(f(s,t))return true;
        vector<int>pref(n+1,-1),suff(n+1,m);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m&&t[j]!=s[i])j++;
            if(j==m){
                for(int k=i+1;k<=n;k++)pref[k]=m;
                break;
            }
            pref[i+1]=j;
            j++;
        }
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0&&t[j]!=s[i])j--;
            if(j<0){
                for(int k=i;k>=0;k--)suff[k]=-1;
                break;
            }
            suff[i]=j;
            j--;
        }
        for(int i=0;i<n;i++){
            if(pref[i]+1<suff[i+1]){
                return true;
            }
        }
        return false;
    }
};