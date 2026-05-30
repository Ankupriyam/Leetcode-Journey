class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] == '1')return false;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int last = -1;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(int j = max(i + minJump, last); j <= min(i + maxJump, n - 1); j++){
                if(!vis[j] && s[j] == '0'){
                    if(j==n-1)return true;
                    vis[j] = true;
                    q.push(j);
                } 
            }
            last = max(last,i+maxJump+1);
        } 
        return false;
    }
};