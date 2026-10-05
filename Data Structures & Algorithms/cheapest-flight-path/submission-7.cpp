class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<pair<int, int>>> adjList(n);
        vector<bool> visited(n, false);
        vector<int> indegree(n,0);
        for (auto f : flights) {
            adjList[f[0]].push_back({f[2], f[1]});
            indegree[f[0]]++;
        }
        pq.push({0, {src, 0}});
        int min_price = INT_MAX;
        while (!pq.empty()) {
            auto [price, dest_k] = pq.top();
            pq.pop();
            int dest = dest_k.first;
            int curr_k = dest_k.second;
            if (dest == dst) {
                min_price = min(price, min_price);
                continue;
            }
            if (curr_k == k+1 || visited[dest]) continue;
            if(--indegree[dest]==0) 
                visited[dest] = true;
            curr_k++;
            for (auto [p, d] : adjList[dest]) {
                if (visited[d]) continue;
                pq.push({price + p, {d, curr_k}});
            }
        }
        if (min_price == INT_MAX) return -1;
        return min_price;
    }
};
