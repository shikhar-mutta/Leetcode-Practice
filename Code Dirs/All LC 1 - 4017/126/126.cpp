// Link: https://leetcode.com/problems/word-ladder-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * L^2) BFS layer build + path enumeration  SC: O(n * L)
// Approach: BFS from beginWord tracking each word's level and its set of predecessors at the level below,
// stop once endWord's level is reached, then DFS backward from endWord through predecessors to enumerate all paths
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> preds;
        unordered_map<string, int> level;
        level[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        bool found = false;
        int curLevel = 0;

        while (!q.empty() && !found) {
            curLevel++;
            unordered_set<string> visitedThisLevel;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string word = q.front(); q.pop();
                for (int j = 0; j < (int)word.size(); j++) {
                    string next = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[j]) continue;
                        next[j] = c;
                        if (!dict.count(next)) continue;
                        if (level.count(next) && level[next] < curLevel) continue;
                        if (!level.count(next)) {
                            level[next] = curLevel;
                            visitedThisLevel.insert(next);
                            q.push(next);
                        }
                        preds[next].push_back(word);
                        if (next == endWord) found = true;
                    }
                }
            }
        }
        if (!found) return res;

        vector<string> path = {endWord};
        function<void(string&)> dfs = [&](string& word) {
            if (word == beginWord) {
                vector<string> full(path.rbegin(), path.rend());
                res.push_back(full);
                return;
            }
            for (auto& p : preds[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };
        dfs(endWord);
        return res;
    }
};
