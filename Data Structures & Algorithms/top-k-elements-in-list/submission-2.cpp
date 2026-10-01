class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        for (int i : nums) {
            max_freq = max(max_freq, ++freq[i]);
        }
        unordered_map<int,vector<int>> indexfreq(max_freq + 1);
        for (auto f : freq) {
            indexfreq[f.second].push_back(f.first);
        }
        vector<int> result;
        for (int i = max_freq; i >= 1; i--) {
            if (!indexfreq[i].empty()) {
                for(int num:indexfreq[i]){
                    --k;
                    result.push_back(num);
                    if(k==0){
                        return result;
                    }
                }
            }
        }
        return result;
    }
};
