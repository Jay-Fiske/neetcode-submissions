class Solution {
int helper(string &s,vector<int> &ways,int i){
    if(i==s.size()){
        return 1;
    }
    if(s[i]=='0'){
        return 0;
    }
    if(ways[i]!=-1){
        return ways[i];
    }
    int total = 0;
    total += helper(s,ways,i+1);
    if(s.size()>i+1){
        int twodigit = stoi(s.substr(i,2));
        if(twodigit>=10 && twodigit<=26){
            total += helper(s,ways,i+2);
        }
    }
    return ways[i]=total;
}
public:
    int numDecodings(string s) {
        vector<int> ways(s.size(),-1);
        return helper(s,ways,0);   
    }
};
