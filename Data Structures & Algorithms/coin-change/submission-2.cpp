class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> coinSet(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int minimum_cost = 10001;
            if (coinSet.find(i) != coinSet.end()) {
                dp[i] = 1;
                continue;
            }
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] >= i) {
                    break;
                }
                int curr = dp[i - coins[j]] + 1;
                minimum_cost = min(minimum_cost, curr);
            }
            dp[i] = minimum_cost;
        }
        if (dp[amount] == 10001) return -1;
        return dp[amount];
    }
};
