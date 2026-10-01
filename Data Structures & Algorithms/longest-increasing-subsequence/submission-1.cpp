class Solution {
   private:
    int findLowerBound(vector<int> tails,int x) {
        int low = 0, high = tails.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (tails[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        tails.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (tails.back() < nums[i]) {
                tails.push_back(nums[i]);
                continue;
            }
            int lower_bound = findLowerBound(tails, nums[i]);
            tails[lower_bound] = nums[i];
        }
        return tails.size();
    }
};
