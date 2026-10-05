class Solution {
    vector<pair<int, int>> nextDirections = {{-1, 0}, {0, -1}};
    vector<pair<int, int>> prevDirections = {{1, 0}, {0, 1}};

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 0));
        ways[m - 1][n - 1] = 1;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({m - 1, n - 1});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (visited[i][j] == 2) continue;
            for (auto [di, dj] : prevDirections) {
                int ni = i + di;
                int nj = j + dj;
                if (ni == m || nj == n) continue;
                ways[i][j] += ways[ni][nj];
            }
            visited[i][j] = 2;
            for (auto [di, dj] : nextDirections) {
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || nj < 0 || visited[ni][nj]) continue;
                visited[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<ways[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ways[0][0];
    }
};
