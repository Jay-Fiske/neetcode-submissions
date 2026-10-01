class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(string s:strs){
            encodedString += to_string(s.size()) + '#';
            encodedString += s;

        }
        return encodedString;

    }

    vector<string> decode(string s) {
        vector<string> decodedVector;
        int i = 0;
        while(i<s.size()){
            string subLen;
             while(s[i]!='#'){
                subLen += s[i];
                i++;
            }
            int len = stoi(subLen);
            i++;
            decodedVector.push_back(s.substr(i,len));
            i+=len;
        }
        return decodedVector;

    }
};
