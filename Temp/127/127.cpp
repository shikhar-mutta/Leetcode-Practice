// Link: https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * L^2)  SC: O(n * L)
// Approach: BFS over one-letter-different transformations, trying all 26 letters at each position
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);
        while (!q.empty()) {
            auto [word, dist] = q.front(); q.pop();
            if (word == endWord) return dist;
            for (int j = 0; j < (int)word.size(); j++) {
                string next = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == word[j]) continue;
                    next[j] = c;
                    if (dict.count(next)) {
                        dict.erase(next);
                        q.push({next, dist + 1});
                    }
                }
            }
        }
        return 0;
    }
};
