class Solution {
public:
    int f(int x){
        int mini=10,maxi=-1;
        while(x!=0){
            int rem=x%10;
            maxi=max(maxi,rem);
            mini=min(mini,rem);
            x/=10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxi=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,f(nums[i]));
        }
        for(int i=0;i<nums.size();i++){
            if(f(nums[i])==maxi){
                sum+=nums[i];
            }
        }
        return sum;
    }
};