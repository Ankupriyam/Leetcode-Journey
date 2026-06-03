class Solution {
public:
    int f(vector<int> &l1,vector<int>&l2,vector<int>& w1,vector<int>&w2){
        int ans=1e9,ans2=1e9;
        for(int i=0;i<l1.size();i++){
            ans=min(ans,l1[i]+l2[i]);
        }

        for(int i=0;i<w1.size();i++){
            if(w1[i]>=ans){
                ans2=min(ans2,w1[i]+w2[i]);
            }else{
                ans2=min(ans2,ans+w2[i]);
            }
        }
        return ans2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int> waterDuration) {
       return min (f(landStartTime,landDuration,waterStartTime,waterDuration),f(waterStartTime ,waterDuration ,landStartTime,landDuration));

    }
};