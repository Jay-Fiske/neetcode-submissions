class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        wordList.push_back(beginWord);
        map<string, vector<string>> dict;
        int n = beginWord.size();
        unordered_set<string> visited;
        for (const string& word : wordList) {
            for (int i = 0; i < n; i++) {
                string pattern = word;
                pattern[i] = '*';
                dict[pattern].push_back(word);
            }
        }
        queue<string> q;
        int ladder = 1;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                if (curr == endWord) {
                    return ladder;
                }
                visited.insert(curr);
                q.pop();
                for (int i = 0; i < n; i++) {
                    string pattern = curr;
                    pattern[i] = '*';
                    for (const string& pMatch : dict[pattern]) {
                        if (!visited.count(pMatch)) {
                            q.push(pMatch);
                        }
                    }
                }
               
            }
             ladder++;
        }
        return 0;
    }
};
