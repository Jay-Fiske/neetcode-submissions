class Solution {
    bool recursive_helper(vector<int>& nums, int pos, int target_sum, int curr_sum) {
        for (int i = pos; i < nums.size(); i++) {
            if (curr_sum + nums[i] > target_sum) {
                break;
            }
            if (curr_sum + nums[i] == target_sum) {
                return true;
            }
            if (recursive_helper(nums, i + 1, target_sum, curr_sum + nums[i])) {
                return true;
            }
        }
        return false;
    }

   public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i : nums) {
            target += i;
        }
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;
        sort(nums.begin(), nums.end());
        return recursive_helper(nums, 0, target, 0);
    }
};
