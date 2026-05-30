class Solution {
public:
    #define ll __int128

    ll f2(ll x,int k,ll maxi){
        ll ans=1;
        for(int i=0;i<k;i++){
            ans*=x;
            if(ans>maxi)break;
        }
        return ans;
    }
    ll f1(ll n,int k){
        ll low=0,high=n,ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(f2(mid,k,n)<=n){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        ll left=f1(l,k);
        if(f2(left,k,l)<l)left++;
        ll right=f1(r,k);
        ll x=0;
        return max(x,right-left+1);
    }
};