class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;
        vector<bool> visited(n, false);
        int totalCost = 0;
        for (int i = 0; i < n; i++) {
            int curr = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (curr == -1 || minCost[j] < minCost[curr]))
                {
                    curr = j;
                }
            }
            visited[curr] = true;
            totalCost += minCost[curr];
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    int dist =
                        abs(points[curr][0] - points[j][0]) + abs(points[curr][1] - points[j][1]);
                    minCost[j] = min(minCost[j], dist);
                }
            }
        }
        return totalCost;
    }
};
