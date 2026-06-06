class Solution {
public:
    #define ll long long
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0,count=0;
        int n=nums.size();
        vector<ll>curr(3,-1e9);
        curr[0]=0;
        if(s[0]=='1'){
            curr[1]=nums[0];
        }
        curr[2]=nums[0];
        for(int i=1;i<n;i++){
            vector<ll>ahead(3,-1e9);
            ahead[0]=max(curr[0],curr[1]);
            ahead[2]=max(curr[0],curr[1])+nums[i];
            if(s[i]=='1'){
                ahead[0]=max(ahead[0],curr[2]);
                ahead[1]=max(curr[0],curr[1])+nums[i];
                ahead[2]=max(ahead[2],curr[2]+nums[i]);
            }
            curr=ahead;
        }
        return max(curr[0],curr[1]);
    }
};