class Solution {
private:
    int rep(int n,vector<int>& mem){
        if(n==0 || n==1){
            return 1;
        }
        if(mem[n]!=0){
            return mem[n];
        }
        return mem[n] = rep(n-1,mem)+rep(n-2,mem);
    }
public:
    int climbStairs(int n) {
        vector<int> mem(n+1,0);
        return rep(n,mem);
        
    }
};
