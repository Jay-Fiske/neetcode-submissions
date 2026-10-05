class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 1));
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                ways[i][j] = ways[i + 1][j] + ways[i][j + 1];
            }
        }

        return ways[0][0];
    }
};