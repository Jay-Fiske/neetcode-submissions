class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adjList[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        pq.push({0, k});
        int max_cost = 0;
        while (!pq.empty() && visited.size() != n) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visited.count(node)) continue;

            visited.insert(node);
            max_cost = max(cost, max_cost);
            for (auto e : adjList[node]) {
                if (!visited.count(e.second)) pq.push({e.first + cost, e.second});
            }
        }
        if (visited.size() == n) return max_cost;
        return -1;
    }
};
