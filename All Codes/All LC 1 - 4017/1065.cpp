// Link: https://leetcode.com/problems/index-pairs-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<vector<int>> res;
        int n = text.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = text.substr(i, j - i + 1);
                if (wordSet.count(sub)) res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
