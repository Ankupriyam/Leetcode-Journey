class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1,curr=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                curr++;
                ans=max(ans,curr);
            }else{
                curr=1;
            }
                
        }
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            map<int,int>diff;
            for(int j=i;j<n;j++){
                 if(freq[nums[j]]!=0){
                    diff[freq[nums[j]]]--;
                    if(diff[freq[nums[j]]]==0){
                        diff.erase(freq[nums[j]]);
                    }
                }
                freq[nums[j]]++;
                diff[freq[nums[j]]]++;
               
                if(diff.size()==2){
                    auto it=(diff.begin()->first);
                    auto it2=diff.rbegin()->first;
                    if(it*2==it2){
                        ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};