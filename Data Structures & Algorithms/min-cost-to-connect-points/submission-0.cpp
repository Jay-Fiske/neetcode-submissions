class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 0;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        set<pair<int, int>> unvisited_nodes;
        pair<int,int> curr = {points[0][0],points[0][1]};
        for (int i = 0; i < points.size(); i++) {
            unvisited_nodes.insert({points[i][0], points[i][1]});
        }
        int cost = 0;
        while (!unvisited_nodes.empty()) {
            unvisited_nodes.erase(curr);
                       if (unvisited_nodes.empty())
                break;
            for (pair<int, int> nodes : unvisited_nodes) {
                int dist = abs(nodes.first - curr.first) + abs(nodes.second - curr.second);
                pq.push({dist,nodes});
            }
            int node_cost=0;
            while(!unvisited_nodes.count(pq.top().second)){
            pq.pop();
            }
            curr = pq.top().second;
            cost += pq.top().first;
            pq.pop();
        }
        return cost;
    }
};
