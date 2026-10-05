class Solution {
   private:
    vector<vector<int>> adjList = vector<vector<int>>(26);
    bool dfs(int node, vector<int>& visited, string& result) {
        if (visited[node] == 1) {
            return true;
        }
        if (visited[node] == 2) {
            return false;
        }
        visited[node] = 1;
        for (int i = 0; i < adjList[node].size(); i++) {
            if (dfs(adjList[node][i], visited, result)) {
                return true;
            }
        }
        visited[node] = 2;
        result += static_cast<char>(node + 'a');
        return false;
    }

   public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<bool> hasParent(26, false);
        for (int i = 0; i < n - 1; i++) {
            string curr = words[i];
            string nxt = words[i + 1];
            int p = 0, q = 0;

            while (p < curr.size() && q < nxt.size()) {
                if (curr[p] != nxt[q]) {
                    adjList[curr[p] - 'a'].push_back(nxt[q] - 'a');
                    hasParent[nxt[q] - 'a'] = true;
                    break;
                }
                p++;
                q++;
            }
            if (curr.size() > nxt.size() && q == nxt.size() && curr[p - 1] == nxt[q - 1]) return "";
        }
        string finalResult = "";
        vector<int> visited(26, 0);
        for (string word:words) {
            for(char ch:word){
                if(visited[ch-'a']==0){
                    if(dfs(ch-'a',visited,finalResult)) return "";
                }
            }  
        }
        reverse(finalResult.begin(),finalResult.end());
        return finalResult;
    }
};
