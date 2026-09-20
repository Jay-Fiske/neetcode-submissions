class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dist = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int k = 0; k < s; k++) {
                auto [i, j] = q.front();
                q.pop();
                grid[i][j] = dist;
                if (i + 1 >= 0 && j >= 0 && i + 1 < ROWS && j < COLS && grid[i + 1][j] == INT_MAX) {
                    grid[i + 1][j] = dist + 1;
                    q.push({i + 1, j});
                }
                if (i - 1 >= 0 && j >= 0 && i - 1 < ROWS && j < COLS && grid[i - 1][j] == INT_MAX) {
                    grid[i - 1][j] = dist + 1;
                    q.push({i - 1, j});
                }
                if (i >= 0 && j + 1 >= 0 && i < ROWS && j + 1 < COLS && grid[i][j + 1] == INT_MAX) {
                    grid[i][j + 1] = dist + 1;
                    q.push({i, j + 1});
                }
                if (i >= 0 && j - 1 >= 0 && i < ROWS && j - 1 < COLS && grid[i][j - 1] == INT_MAX) {
                    grid[i][j - 1] = dist + 1;
                    q.push({i, j - 1});
                }
            }
            dist++;
        }
    }
};
