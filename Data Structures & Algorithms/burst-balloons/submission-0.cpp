class Solution {
    int recursion(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (l > r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int k = l; k <= r; k++) {
            int left = recursion(l, k - 1, nums, dp);
            int right = recursion(k + 1, r, nums, dp);

            int coins = nums[l - 1] * nums[k] * nums[r + 1];

            ans = max(ans, left + coins + right);
        }

        return dp[l][r] = ans;
    }

   public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return recursion(1, n - 2, nums, dp);
    }
};