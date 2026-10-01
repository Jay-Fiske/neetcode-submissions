class Solution {
    bool findMatch(string& s, vector<string>& wordDict, int pos, vector<int>& dp) {
        if (pos == s.size()) {
            return true;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        for (string w : wordDict) {
            if (pos + w.size() <= s.size()) {
                if (s.substr(pos, w.size()) == w) {
                    if (findMatch(s, wordDict, pos + w.size(), dp)) {
                        return dp[pos] = 1;
                    }
                }
            }
        }
        return dp[pos] = 0;
    }

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return findMatch(s, wordDict, 0, dp);
    }
};
