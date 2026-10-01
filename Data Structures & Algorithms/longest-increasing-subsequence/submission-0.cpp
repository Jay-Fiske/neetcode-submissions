class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxSeqLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            int maxLen = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    maxLen = max(dp[j], maxLen);
                }
            }
             maxSeqLen = max(maxSeqLen, dp[i] += maxLen);
        }
        return maxSeqLen;
    }
};
