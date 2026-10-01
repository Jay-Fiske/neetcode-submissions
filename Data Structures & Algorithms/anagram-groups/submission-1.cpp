class Solution {
    string hash(string s){
        vector<int> h(26,0);
        for(char c:s){
            h[c-'a']++;
        }
        string hashString;
        for(int freq:h){
            hashString += freq+'#';
        }
        return hashString;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        for(string s:strs){
            string freq = hash(s);
            group[freq].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it:group){
            result.push_back(it.second);
        }
        return result;
        
    }
};
