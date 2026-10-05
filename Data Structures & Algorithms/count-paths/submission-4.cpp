class Solution {
    vector<pair<int, int>> nextDirections = {{-1, 0}, {0, -1}};

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 0));
        if(m==1 || n==1) return 1;
        ways[m - 1][n - 1] = 1;
        int i = m - 1;
        int j = n - 1;
        int prev_j = n - 1;
        int prev_i = m - 1;
        while (i >= 0 && j >= 0) {
            for (auto [di, dj] : nextDirections) {
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || nj < 0) continue;
                ways[ni][nj] += ways[i][j];
            }
            --i;
            ++j;
            if (prev_j >= 1 && (i==-1 || j == n )) {
                i = m - 1;
                j = --prev_j;
                continue;
               // cout<<prev_j<<" ";
            }
            if(prev_i >=1 && (i==-1 || j==n)){
                i = --prev_i;
                j = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << ways[i][j] << " ";
            cout << endl;
        }
        //cout<<i<<" "<<j;

        return ways[0][1] + ways[1][0];
    }
};
