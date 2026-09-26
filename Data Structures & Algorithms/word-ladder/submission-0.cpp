class Solution {
private:
    bool nextPossibleWord(const string& source,
                          const string& target) {

        int diff = 0;

        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                diff++;

                if (diff > 1)
                    return false;
            }
        }

        return diff == 1;
    }

public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words;

        for (const string& word : wordList) {
            words.insert(word);
        }

        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int ladderLen = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                for (auto it = words.begin(); it != words.end();) {

                    string word = *it;

                    if (nextPossibleWord(curr, word)) {

                        if (word == endWord)
                            return ladderLen + 1;

                        q.push(word);

                        // Safely erase
                        it = words.erase(it);
                    }
                    else {
                        ++it;
                    }
                }
            }

            ladderLen++;
        }

        return 0;
    }
};