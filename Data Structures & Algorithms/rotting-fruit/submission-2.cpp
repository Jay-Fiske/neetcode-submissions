class Solution {
    //    private:
    //     void displayGrid(vector<vector<int>>& grid, int r, int c) {
    //         for (int i = 0; i < r; i++) {
    //             for (int j = 0; j < c; j++) {
    //                cout<<grid[i][j]<<" ";
    //             }
    //             cout<<endl;
    //         }
    //     }

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshFruits = 0;
        int time = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshFruits++;
                }
            }
        }
        if(freshFruits==0){
            return 0;
        }
        while (!q.empty()) {
            int s = q.size();
            for (int k = 0; k < s; k++) {
                auto [i, j] = q.front();
                q.pop();
                if (i + 1 < ROWS && grid[i + 1][j] == 1) {
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                    if (--freshFruits == 0) {
                        return time + 1;
                    }
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                    if (--freshFruits == 0) {
                        return time + 1;
                    }
                }
                if (j + 1 < COLS && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;

                    if (--freshFruits == 0) {
                        return time + 1;
                    }
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;

                    if (--freshFruits == 0) {
                        return time + 1;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};
