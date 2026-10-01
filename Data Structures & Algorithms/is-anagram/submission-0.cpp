class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> hash(26,0);
        for(char c:s){
            hash[c-'a']++;
        }
        for(char c:t){
            if(--hash[c-'a']<0){
                return false;
            }
        }
        return true;
        
    }
};
