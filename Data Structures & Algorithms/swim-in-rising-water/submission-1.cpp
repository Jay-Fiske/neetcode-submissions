class Solution {
    vector<int> rank;
    vector<int> parent;
    vector<pair<int,int>> neighbours = {{1,0},{-1,0},{0,1},{0,-1}};
    int find(int x){
        if(parent[x]!=x){
             parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
    void unite(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb){
            return;
        }
        if(rank[pa]>=rank[pb]){
            if(rank[pa]==rank[pb]){
                rank[pa]++;
            }
            parent[pb] = pa;
        }
        else if(rank[pa]<rank[pb]){
            parent[pa] = pb;

        }
    }
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        rank.resize(total,0);
        parent.resize(total);
        vector<pair<int,int>> position(total);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            parent[grid[i][j]] = grid[i][j];
            position[grid[i][j]] = {i,j};
            }
        }
        vector<bool> visited(total, false);
        for(int k=0;k<total;k++){
            visited[k] = true;
            auto [i,j] = position[k];
            for(pair<int,int> nbours:neighbours){
                int ni = i + nbours.first;
                int nj = j + nbours.second;
                if(ni==n||nj==n||ni<0||nj<0) continue;
                if(visited[grid[ni][nj]]) unite(k,grid[ni][nj]);
            }
            if(find(grid[0][0])==find(grid[n-1][n-1])) return k;
            
        }
        return -1;
    }
};
