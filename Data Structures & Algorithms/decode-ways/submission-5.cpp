class Solution {
   public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int prev = 1;
        int prev2 = 1;
        for (int i = 1; i < s.size(); i++) {
            int curr = 0;
            int comb = stoi(s.substr(i - 1, 2));
            if (s[i] != '0') {
             curr = prev;   
            }
            if (comb >= 10 && comb <= 26) {
                curr += prev2;
            }
            if(curr==0){
                return 0;
            }
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
