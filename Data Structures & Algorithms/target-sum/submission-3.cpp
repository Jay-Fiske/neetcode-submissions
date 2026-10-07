class Solution {
   private:
    int sum = 0;
    int recursion(vector<int>& nums, vector<vector<int>>& dp, int curr_sum, int i, int target) {
        if (i == nums.size()) {
            return curr_sum == target;
        }
        int sum_index = curr_sum;
        if (curr_sum < 0) {
            sum_index = 2 * sum + curr_sum+1;
        }
        if (dp[i][sum_index] != -1) {
            return dp[i][sum_index];
        }
        return dp[i][sum_index] = recursion(nums, dp, curr_sum + nums[i], i + 1, target) +
                                  recursion(nums, dp, curr_sum - nums[i], i + 1, target);
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i : nums) {
            sum += abs(i);
        }
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return recursion(nums, dp, 0, 0, target);
    }
};
