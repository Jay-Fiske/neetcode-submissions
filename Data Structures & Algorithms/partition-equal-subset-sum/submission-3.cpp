class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i : nums) {
            target += i;
        }
        if (target % 2 != 0) {
            return false;
        }
        target/=2;

        unordered_set<int> dp;
        dp.insert(0);
        for (int i : nums) {
            for (int sum : dp) {
                dp.insert(sum + i);
            }
        }
        return dp.count(target);
         }
};
