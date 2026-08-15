// Link: https://leetcode.com/problems/letter-case-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^letters) SC: O(n * 2^letters)
// Approach: DFS/backtracking; at each letter position branch into lowercase and uppercase, digits pass through unchanged.
class Solution {
    vector<string> res;
    void dfs(string& s, int i) {
        if (i == (int)s.size()) { res.push_back(s); return; }
        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
            dfs(s, i+1);
            s[i] = toupper(s[i]);
            dfs(s, i+1);
        } else {
            dfs(s, i+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return res;
    }
};
