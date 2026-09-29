class Solution {
   public:
    string longestPalindrome(string s) {
        string t = "~";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += '#';
        t += ')';
        int n = t.size();
        int C = 0;
        int R = 0;
        int centreIndex=0;
        int maxRadius=0;
        vector<int> P(n,0);
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2*C - i;
            if(i<R){
                P[i] = min(R-i,P[mirror]);
            }
            while(t[i+P[i]+1]==t[i-P[i]-1]){
                P[i]++;
            }
            if(R<P[i]){
                R = P[i]+i;
                C = i;
            }
            if(maxRadius<P[i]){
                maxRadius = P[i];
                centreIndex = i;
            }
        }
        int start = (centreIndex-maxRadius)/2;
        return s.substr(start,maxRadius);
    }
};