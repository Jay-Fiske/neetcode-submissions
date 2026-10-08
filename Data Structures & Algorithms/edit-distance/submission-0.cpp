class Solution {
    int recursion(int i, int j, string& w1, string& w2, unordered_map<string, int>& dp) {
        if (i == w1.size() && j == w2.size()) {
            return 0;
        }
        if (i == w1.size() || j == w2.size()) {
            return abs((int)w1.size() - (int)w2.size());
        }
        if (dp.find(w1) != dp.end()) {
            return dp[w1];
        }
        if (w1[i] == w2[j]) {
            return dp[w1] = recursion(i + 1, j + 1, w1, w2,dp);
        }
        // Insert jth char at ith pos
        string w1_i = w1.substr(0, i) + w2[j] + w1.substr(i, w1.size() - i);
        int ins = 1 + recursion(i + 1, j + 1, w1_i, w2,dp);

        // Delete char at ith pos
        string w1_d = w1.substr(0, i) + w1.substr(i + 1, w1.size() - i - 1);
        int del = 1 + recursion(i, j, w1_d, w2,dp);

        // Replace ith char with jth char
        string w1_r = w1;
        w1_r[i] = w2[j];
        int repl = 1 + recursion(i + 1, j + 1, w1_r, w2,dp);

        return dp[w1] = min({ins, del, repl});
    }

   public:
    int minDistance(string word1, string word2) {
                unordered_map<string, int> dp;
        return recursion(0, 0, word1, word2, dp);
    }
};
