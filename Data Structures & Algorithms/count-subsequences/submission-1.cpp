class Solution {
    string src, tgt;
    int recursion(int i, int j, vector<vector<int>>& dp) {
        if (j == tgt.size()) {
            return 1;
        }
        if (i == src.size()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int take = 0, not_take = 0;
        if (src[i] == tgt[j]) {
            take = recursion(i + 1, j + 1,dp);
        }
        not_take = recursion(i + 1, j,dp);
        return dp[i][j] = take + not_take;
    }

   public:
    int numDistinct(string s, string t) {
        src = s;
        tgt = t;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return recursion(0, 0,dp);
    }
};
