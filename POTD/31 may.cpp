class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int x:asteroids){
            if(curr<(long long)x){
                return false;
            }
            curr+=x;
        }
        return true;
    }
};