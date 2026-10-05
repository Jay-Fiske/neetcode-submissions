class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Find characters that actually exist
        for (string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string& a = words[i];
            string& b = words[i + 1];

            int j = 0;

            while (j < a.size() && j < b.size() &&
                   a[j] == b[j]) {
                j++;
            }

            // Invalid prefix case
            if (j == b.size() && a.size() > b.size()) {
                return "";
            }

            // Found first different character
            if (j < a.size() && j < b.size()) {

                int u = a[j] - 'a';
                int v = b[j] - 'a';

                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        // Topological sort
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string result;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            result += char(node + 'a');

            for (int nei : adj[node]) {

                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Not all characters processed -> cycle
        if (result.size() != count(present.begin(), present.end(), true)) {
            return "";
        }

        return result;
    }
};