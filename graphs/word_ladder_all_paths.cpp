#include <bits/stdc++.h>
using namespace std;

// Find all shortest transformation sequences.
vector<vector<string>> findLadders(
    string beginWord,
    string endWord,
    vector<string>& wordList
) {
    unordered_set<string> dictionary(
        wordList.begin(),
        wordList.end()
    );

    vector<vector<string>> result;

    if (!dictionary.count(endWord))
        return result;

    queue<vector<string>> q;
    q.push({beginWord});

    bool found = false;

    while (!q.empty() && !found) {
        int levelSize = q.size();

        unordered_set<string> usedThisLevel;

        while (levelSize--) {
            vector<string> path = q.front();
            q.pop();

            string word = path.back();

            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;

                    if (dictionary.count(word)) {
                        vector<string> newPath = path;
                        newPath.push_back(word);

                        if (word == endWord) {
                            result.push_back(newPath);
                            found = true;
                        } else {
                            q.push(newPath);
                        }

                        usedThisLevel.insert(word);
                    }
                }

                word[i] = original;
            }
        }

        for (const string& word : usedThisLevel)
            dictionary.erase(word);
    }

    return result;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog",
        "lot", "log", "cog"
    };

    vector<vector<string>> paths =
        findLadders(beginWord, endWord, wordList);

    for (auto& path : paths) {
        for (string& word : path)
            cout << word << " ";

        cout << '\n';
    }

    return 0;
}
