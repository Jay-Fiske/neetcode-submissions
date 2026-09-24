class Solution {
   private:
    bool dfs(unordered_map<int, vector<int>>& preMap, vector<bool>& visiting, int i) {
        if (visiting[i]) {
            return false;
        }
        if (preMap[i].empty()) {
            return true;
        }
        visiting[i] = true;
        for (int j = preMap[i].size() - 1; j >= 0; j--) {
            bool possible = dfs(preMap, visiting, preMap[i][j]);
            if (possible == false) {
                return false;
            }
            preMap[i].pop_back();
        }
        visiting[i] = false;

        return true;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visiting(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            bool possible=true;
            if (preMap[i].empty() == false) {
                 possible = dfs(preMap, visiting, i);
            }
            if (possible == false) {
                cout<<i;
                return false;
            }
        }
        return true;
    }
};
