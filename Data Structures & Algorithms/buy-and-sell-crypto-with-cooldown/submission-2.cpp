class Solution {
    int recursion(int i,vector<int>& prices, int holding, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][holding] != -1) return dp[i][holding];
        if(!holding){
            int buy = -prices[i] + recursion(i+1,prices,1,dp);
            int skip = recursion(i+1,prices,0,dp);
            return dp[i][holding] = max(buy,skip);
        }
        else{
        int sell = prices[i] + recursion(i+2,prices,0,dp);
        int skip = recursion(i+1,prices,1,dp);
        return dp[i][holding] = max(skip,sell);
        }
        
    }

   public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        int ans = recursion(0, prices, 0, dp);
        // for (vector<int> i : dp) {
        //     for(int j:i)
        //     cout << j << " ";
        //     cout<<endl;
        // }
        return ans;
    }
};
