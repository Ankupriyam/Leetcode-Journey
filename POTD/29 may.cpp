class Solution {
public:
    int f(int num){
        int x=0;
        while(num!=0){
            x+=num%10;
            num/=10;
        }
        return x;
    }
    int minElement(vector<int>& nums) {
        int ans=1e9;
        for(int i=0;i<nums.size();i++){
            nums[i]=f(nums[i]);
            ans=min(ans,nums[i]);
        }
        return ans;
    }
};