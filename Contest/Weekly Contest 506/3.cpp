class Solution {
public:
    #define ll long long
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size(),n=units[0].size();
        ll ans=0;
        if(n==1){
            for(int i=0;i<m;i++){
                ans+=units[i][0];
            }
            return ans;
        }
        for(int i=0;i<m;i++){
            sort(units[i].begin(),units[i].end());
        }
        sort(units.begin(),units.end(),[&](const vector<int>&a,const vector<int>&b){
            if(a[1]!=b[1]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        ans=0;
        int mini=1e9;
        for(int i=1;i<m;i++){
            ans+=units[i][1];
        }
        for(int i=0;i<m;i++){
            mini=min(mini,units[i][0]);
        }
        return ans+mini;
    }
};