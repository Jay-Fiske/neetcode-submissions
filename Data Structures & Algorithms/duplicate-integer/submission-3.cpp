class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int i:nums){
            if (store.count(i)){
                return true;
            }
            store.insert(i);
        }
        return 0;
    }
};