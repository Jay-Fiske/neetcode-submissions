class Solution {
    string t1,t2;
    int len1,len2;
    int recursion(int i,int j,vector<vector<int>>&dp){
        if(i==len1 || j==len2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]) return dp[i][j] = 1 + recursion(i+1,j+1,dp);
        return dp[i][j] = max(recursion(i+1,j,dp),recursion(i,j+1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1;
        t2 = text2;
        len1 = text1.size();
        len2 = text2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return recursion(0,0,dp); 
    }
};
