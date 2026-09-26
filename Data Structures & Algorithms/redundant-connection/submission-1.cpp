class Solution {
    vector<int> rank, parent;
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unite(int source, int target) {
        int pSource = findParent(source);
        int pTarget = findParent(target);
        if (pSource == pTarget) {
            return true;
        }
        if (rank[pSource] == rank[pTarget]) {
            rank[pSource]++;
            parent[pTarget] = pSource;
        } else if (rank[pSource] > rank[pTarget]) {
            parent[pTarget] = pSource;
        } else {
            parent[pSource] = pTarget;
        }
        return false;
    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
        for (auto e : edges) {
            if (unite(e[0], e[1])) {
                return e;
            }
        }
    }
};
