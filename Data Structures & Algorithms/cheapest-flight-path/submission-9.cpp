class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = price;
            for (auto &f : flights) {
                int source = f[0];
                int dest = f[1];
                int cost = f[2];
                if (price[source] == INT_MAX) continue;
                temp[dest] = min(temp[dest], price[source] + cost);
            }
            price = temp;
        }
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};
