class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        string t1 = '0' + text1;
        string t2 = '0' + text2;
        int len1 = 1 + text1.size();
        int len2 = 1 + text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (t1[i] == t2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1-1][len2-1];
    }
};
