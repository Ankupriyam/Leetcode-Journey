class Solution {
public:
    int dp[600][600];
    int f(int i, int j, vector<int>& piles) {
        if (j < i)
            return 0;
        if (dp[i][j] != -1e17)
            return dp[i][j];
        return dp[i][j] = max(piles[i] - f(i + 1, j, piles),piles[j] - f(i, j - 1, piles));
    }
    bool stoneGame(vector<int>& piles) { 
        fill(&dp[0][0], &dp[0][0] + 600 * 600, -(long long)1e17);
        return f(0,piles.size()-1,piles);
     }
};