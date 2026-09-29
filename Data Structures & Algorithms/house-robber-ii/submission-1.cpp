class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prev = 0;
        int prev2 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }
        int maxMoney0 = max(prev2, prev);
        prev2 = prev = 0;
        for (int i = 1; i < nums.size(); i++) {
            int curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }
        return max(maxMoney0, max(prev, prev2));
    }
};
