class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr="";
        for(string s:strs){
            int len = s.size();
            encodedStr += to_string(len);
            encodedStr += "#";
            encodedStr += s;
        }
        return encodedStr;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i<s.size()){
            string strCount = "";
            while(s[i]!='#'){
                strCount += s[i++];
            }
            int count = stoi(strCount);
            i++;
            string curr = s.substr(i, count);
            i += count;
            result.push_back(curr);
        }
        return result;
    }
};