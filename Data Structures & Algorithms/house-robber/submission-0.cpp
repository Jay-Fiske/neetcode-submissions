class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        int prev = 0;
        for(int house:nums){
            int curr = house + max(prev1,prev2);
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        return max(prev,prev1);
        
    }
};
