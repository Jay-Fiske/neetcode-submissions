class Solution {
   private:
    int ROWS, COLS;
    pair<int, int> dfs(vector<vector<int>>& heights, vector<vector<int>>& visited,
                       vector<vector<pair<int, int>>>& ocean_reached, int i, int j, int curr,
                       vector<vector<int>>& ans) {
        if (i < 0 || j < 0) {
            return {1, 0};
        }
        if (i == ROWS || j == COLS) {
            return {0, 1};
        }
        if (heights[i][j] > curr) {
            return {0, 0};
        }
        if (visited[i][j] == 1) {
            return {0, 0};
        }
        if (visited[i][j] == 2) {
            return ocean_reached[i][j];
        }
        visited[i][j] = 1;
        pair<int, int> left = dfs(heights, visited, ocean_reached, i, j - 1, heights[i][j], ans);
        pair<int, int> up = dfs(heights, visited, ocean_reached, i - 1, j, heights[i][j], ans);
        pair<int, int> right = dfs(heights, visited, ocean_reached, i, j + 1, heights[i][j], ans);
        pair<int, int> down = dfs(heights, visited, ocean_reached, i + 1, j, heights[i][j], ans);
        ocean_reached[i][j].first = left.first || up.first || right.first || down.first;
        ocean_reached[i][j].second = left.second || up.second || right.second || down.second;
        visited[i][j] = 2;
        if (ocean_reached[i][j].first == 1 && ocean_reached[i][j].second == 1) {
            ans.push_back({i, j});
        }
        return ocean_reached[i][j];
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        int count = 0;
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
        vector<vector<pair<int, int>>> ocean_reached(ROWS, vector<pair<int, int>>(COLS, {0, 0}));
        vector<vector<int>> ans;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (visited[i][j] == 0)
                    dfs(heights, visited, ocean_reached, i, j, heights[i][j], ans);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!ocean_reached[i][j].first || !ocean_reached[i][j].second) {
                    if (ocean_reached[i][j].first == 0 && i - 1 >= 0 &&
                        heights[i - 1][j] == heights[i][j] && ocean_reached[i - 1][j].first) {
                        ocean_reached[i][j].first = 1;
                    }
                    if (ocean_reached[i][j].first == 0 && j - 1 >= 0 &&
                        heights[i][j - 1] == heights[i][j] && ocean_reached[i][j - 1].first) {
                        ocean_reached[i][j].first = 1;
                    }
                    if (ocean_reached[i][j].second == 0 && i - 1 >= 0 &&
                        heights[i - 1][j] == heights[i][j] && ocean_reached[i - 1][j].second) {
                        ocean_reached[i][j].second = 1;
                    }
                    if (ocean_reached[i][j].second == 0 && j - 1 >= 0 &&
                        heights[i][j - 1] == heights[i][j] && ocean_reached[i][j - 1].second) {
                        ocean_reached[i][j].second = 1;
                    }
                    if (ocean_reached[i][j].first && ocean_reached[i][j].second) {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};
