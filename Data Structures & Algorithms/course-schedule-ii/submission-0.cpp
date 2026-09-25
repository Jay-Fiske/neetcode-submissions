class Solution {
   private:
    bool dfs(vector<int>& state, vector<vector<int>>& preMap, vector<int>& order, int course) {
        if (state[course] == 1) {
            return false;
        }
        if (state[course] == 2) {
            return true;
        }
        state[course] = 1;
        for (int c : preMap[course]) {
            if (!dfs(state, preMap, order, c)) return false;
        }
        state[course] = 2;
        order.push_back(course);
        return true;
    }

   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses,0);
        vector<vector<int>> preMap(numCourses);
        vector<int> order;
        for (auto pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(state, preMap, order, c)) return {};
        }
        return order;
    }
};
