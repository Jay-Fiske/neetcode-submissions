class Solution {
    int recursion_helper(vector<int>& cost, vector<int>& stepCost, int size, int step) {
        if (step >= size) {
            return 0;
        }
        if (stepCost[step] != -1) {
            return stepCost[step];
        }
        int incr1 = recursion_helper(cost, stepCost, size, step + 1);
        int incr2 = recursion_helper(cost, stepCost, size, step + 2);
        return stepCost[step] = min(incr1, incr2) + cost[step];
    }

   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> stepCost(n, -1);
        return min(recursion_helper(cost, stepCost, n, 0), recursion_helper(cost, stepCost, n, 1));
    }
};
