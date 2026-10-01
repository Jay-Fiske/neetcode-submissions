class Solution {
    int hash(string s){
        vector<int> h(26,0);
        for(char c:s){
            h[c-'a']++;
        }
        int hashnum=0;
        for(int freq:h){
            hashnum = hashnum*10 + freq;
        }
        return hashnum;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> group;
        for(string s:strs){
            int freq = hash(s);
            group[freq].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it:group){
            result.push_back(it.second);
        }
        return result;
        
    }
};
