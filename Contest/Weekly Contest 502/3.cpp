class Solution {
public:
    
    bool check2(pair<int, int> p, int i, int j, int x) {
        if (((i - x) <= p.first && (p.first <= i) && (j - x) <= p.second &&
             p.second <= j && !((i - x) == p.first && (j - x) == p.second))) {
            return true;
        }
        if (((i - x) <= p.first && (p.first <= i) && (j + x) >=p.second &&
             p.second >= j && !((i - x) == p.first && (j + x) == p.second))) {
            return true;
        }
        if (((i + x) >= p.first && (p.first >= i) && (j + x) >=p.second &&
             p.second >= j && !((i + x) == p.first && (j + x) == p.second))) {
            return true;
        }
        if (((i + x) >= p.first && (p.first >= i) && (j - x) <=p.second &&
             p.second <= j && !((i + x) == p.first && (j - x) == p.second))) {
            return true;
        }
        return false;
    }
    bool check(int x, map<int, vector<pair<int, int>>>& mp, int i, int j, int n,
               int m, vector<vector<int>>& matrix) {
        auto it = mp.upper_bound(x);
        for (; it != mp.end(); it++) {
            auto& v = it->second;
            for (auto& p : v) {
                if (check2(p,i,j,x)){
                    return false;
                }
            }
        }
        return true;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j]==0)continue;
                mp[matrix[i][j]].push_back({i, j});
            }
        }
        // vector<vector<bool>>found(n,vector<bool>(m,false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j]==0)continue;
                if (check(matrix[i][j], mp, i, j, n, m, matrix)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};