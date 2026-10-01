class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> difference(nums.size());
        for(int i=0;i<nums.size();i++){
            int diff = target-nums[i];
            if (difference.count(diff)){
                return {difference[diff],i};
            }
            difference[nums[i]]=i;
        }
        return {};
    }
};
