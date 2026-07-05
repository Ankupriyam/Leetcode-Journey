class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mid=-1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(i==nums.size()/2){
                mid=nums[i];
            }
        }
        return mp[mid]==1;
    }
};