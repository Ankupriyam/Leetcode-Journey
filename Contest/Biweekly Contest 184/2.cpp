class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        long long ans=0,count=0;
        if(n==1){
           ans=1;
        }else{
            for(int i=1;i<=n-1;i+=2){
                brightness-=3;
                ans++;
                if(brightness<=0){
                    break;
                }
            }
        }
        int maxi=intervals[0][0];
        for(int i=0;i<intervals.size();i++){
            maxi=max(maxi,intervals[i][0]);
            if(intervals[i][1]>=maxi){
                count+=intervals[i][1]-maxi+1;
                maxi=intervals[i][1]+1;
            }
            maxi=max(maxi,intervals[i][1]);
        }
        return ans*count;
    }
};