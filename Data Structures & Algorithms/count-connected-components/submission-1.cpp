class Solution {
void dfs(vector<vector<int>> &adj_list,vector<bool> &visited,int curr){
    visited[curr] = true;
    for(int neighbour:adj_list[curr]){
        if(visited[neighbour]==false){
            dfs(adj_list,visited,neighbour);
        }
    }
}
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_of_comp = 0;
        vector<vector<int>> adj_list(n);
        for(auto e:edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                num_of_comp++;
                dfs(adj_list,visited,i);
            }
        }
        return num_of_comp;
    }
};
