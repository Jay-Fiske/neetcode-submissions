class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = true;
        int max_elevation = grid[ROWS-1][COLS-1];
        while(!pq.empty()){
            auto [elevation,position] = pq.top();
            auto [i,j] = position;
            pq.pop();
            max_elevation = max(max_elevation,elevation);
            vector<pair<int,int>> next_pos = {{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
            for(auto [ni,nj]:next_pos){
                if(ni<0||ni==ROWS||nj<0||nj==COLS||visited[ni][nj]==true){
                    continue;
                }
                if((ni==ROWS-1)&&(nj==COLS-1)){
                    return max_elevation;
                }
                visited[ni][nj] = true;
                pq.push({grid[ni][nj],{ni,nj}});
            }

        }
        return max_elevation;
    }
};
