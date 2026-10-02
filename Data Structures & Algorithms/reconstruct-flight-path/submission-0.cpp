class Solution {
   private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    void dfs(vector<string>& result,string airport){
        while(!graph[airport].empty()){
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(result,next);
        }
        result.push_back(airport);
    }

   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string> t:tickets){
            graph[t[0]].push(t[1]);
        }
        vector<string> result;
        dfs(result,"JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
