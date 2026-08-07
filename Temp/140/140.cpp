// Link: https://leetcode.com/problems/word-break-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * 2^n) worst case, memoized  SC: O(n^2)
// Approach: memoized DFS start-index -> list of possible suffix sentences, combining a matched prefix word
// with each recursively-computed suffix sentence
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        function<vector<string>(int)> dfs = [&](int start) -> vector<string> {
            if (memo.count(start)) return memo[start];
            vector<string> res;
            if (start == (int)s.size()) { res.push_back(""); return res; }
            for (int end = start + 1; end <= (int)s.size(); end++) {
                string word = s.substr(start, end - start);
                if (dict.count(word)) {
                    for (auto& suffix : dfs(end)) {
                        res.push_back(suffix.empty() ? word : word + " " + suffix);
                    }
                }
            }
            memo[start] = res;
            return res;
        };
        return dfs(0);
    }
};
