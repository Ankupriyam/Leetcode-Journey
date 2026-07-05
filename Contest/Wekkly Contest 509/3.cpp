class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    int divisibleGame(vector<int>& nums) {
        map<int,ll>mp;
        for(ll x:nums){
            for(int i=1;i<=sqrt(x);i++){
                if(x%i==0){
                    mp[i]+=x;
                    if(i*i!=x){
                        mp[x/i]+=x;
                    }
                }
            }
        }
        mp.erase(1);
        if(mp.empty()){
            return (mod-2)%mod;
        }
        ll maxi=-1e18,ans=-1;
        for(auto &it:mp){
            if(it.second<=maxi){
                continue;
            }
            ll sum=-1e18,curr=0;
            for(ll x:nums){
                if(x%it.first==0){
                    if(curr<0){
                        curr=x;
                    }else{
                        curr+=x;
                    }
                }else{
                     if(curr<0){
                        curr=-x;
                    }else{
                        curr-=x;
                    }
                    
                }
                if(curr>sum){
                    sum=curr;
                }
            }
            if(sum>maxi){
                maxi=sum;
                ans=it.first;
            }
        }
        ll final=(maxi%mod+mod)%mod;
        final=(final*(ans%mod))%mod;
        return final;
    }
};