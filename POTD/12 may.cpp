class Solution {
public:
    #define ll long long

    bool f(ll mid,vector<vector<int>>& tasks){
        for(auto & v:tasks){
            if(v[1]>mid){
                return false;
            }
            mid-=v[0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        //minimum jaida wala first // actual
        sort(tasks.begin(),tasks.end(),[&](const vector<int>&a,const vector<int>&b){
            if(a[1]-a[0]!=b[1]-b[0] ){
                return a[1]-a[0]>b[1]-b[0];
            }
            return a[1]>b[1];
        });
        ll low=0,high=0;
        for(int i=0;i<tasks.size();i++){
            low+=tasks[i][0];
            high+=tasks[i][1];
        }
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(f(mid,tasks)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};