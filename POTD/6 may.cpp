class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> box(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                box[i][j] = boxGrid[m - 1 - j][i];
            }
        }
        int j = 0;
        while (j < m) {
            int i = n - 1, li = n - 1;
            while (i >= 0) {
                if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[li--][j] = '#';
                } else if (box[i][j] == '*') {
                    li = i - 1;
                }
                i--;
            }
            j++;
        }
        return box;
    }
};