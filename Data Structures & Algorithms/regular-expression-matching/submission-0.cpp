class Solution {
    bool recursion(int i, int j, string& s, string& p, vector<vector<int>> &dp) {
        if (j == p.size()) {
            return i == s.size();
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        bool ans;
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool skip = recursion(i,j+2,s,p,dp);
            bool use  = match && recursion(i+1,j,s,p,dp);
            ans = skip || use;
        }
        else{
            ans = match && recursion(i+1,j+1,s,p,dp);
        }
        return dp[i][j] = ans;
    }

   public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return recursion(0,0,s,p,dp);
    }
};
