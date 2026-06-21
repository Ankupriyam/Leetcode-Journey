class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        int mini = 1e9, maxi = -1;
        vector<int> vis(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                mini = max(0, i - lights[i]);
                maxi = min(n - 1, i + lights[i]);
                vis[mini] += 1;
                vis[maxi + 1] += -1;
            }
        }
        int sum = 0, ans = 0;
        maxi=0;
        for (int i = 0; i < n;i++) {
            sum += vis[i];
            if (sum > 0) {
               if(maxi>0){
                   ans+=(maxi+2)/3;
                   maxi=0;
               }
            }else{
                maxi++;
            }
           
        }
        if(maxi>0){
            ans+=(maxi+2)/3;
        }
        return ans;
    }
};