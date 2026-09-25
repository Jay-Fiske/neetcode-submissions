class Solution {
   private:
    bool dfs(vector<bool>& visited, vector<vector<int>>& adj_list, int curr, int parent) {
        if(visited[curr]==true){
            return false;
        }
        visited[curr] = true;
        for(int neighbour:adj_list[curr]){
            if(neighbour==parent){
                continue;
            }
            if(visited[neighbour]){
                return false;
            }
            if(!dfs(visited,adj_list,neighbour,curr)){
                return false;
            }
        }
        return true;

    }

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<bool> visited(n, false);
        vector<vector<int>> adj_list(n);
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        if (!dfs(visited, adj_list, 0, -1)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
