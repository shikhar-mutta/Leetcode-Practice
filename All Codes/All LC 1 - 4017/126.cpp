// Link: https://leetcode.com/problems/word-ladder-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N * L^2 + N * L^2)
    //  SC: O(N * L^2)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return res;
        dict.erase(beginWord);

        // BFS level by level, recording all predecessors of each word
        unordered_map<string, vector<string>> parents;
        unordered_set<string> curLevel = {beginWord};
        bool found = false;

        while (!curLevel.empty() && !found)
        {
            // remove this level's words so we only take forward edges
            for (const string &w : curLevel)
                dict.erase(w);

            unordered_set<string> nextLevel;
            for (const string &word : curLevel)
            {
                string cur = word;
                for (int i = 0; i < (int)cur.size(); i++)
                {
                    char orig = cur[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == orig)
                            continue;
                        cur[i] = c;
                        if (dict.count(cur))
                        {
                            if (cur == endWord)
                                found = true;
                            nextLevel.insert(cur);
                            parents[cur].push_back(word);
                        }
                    }
                    cur[i] = orig;
                }
            }
            curLevel = move(nextLevel);
        }

        if (!found)
            return res;

        // backtrack from endWord to beginWord using parent pointers
        vector<string> path = {endWord};
        function<void(const string &)> backtrack = [&](const string &word)
        {
            if (word == beginWord)
            {
                res.emplace_back(path.rbegin(), path.rend());
                return;
            }
            for (const string &p : parents[word])
            {
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };
        backtrack(endWord);
        return res;
    }
};
