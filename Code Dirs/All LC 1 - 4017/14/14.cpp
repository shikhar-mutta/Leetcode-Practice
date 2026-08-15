// Link: https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(1)
// Approach: compare char-by-char at each index across all strings, stop at first mismatch or shortest string end
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < (int)strs[0].size(); i++) {
            char c = strs[0][i];
            for (auto& s : strs) {
                if (i >= (int)s.size() || s[i] != c) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
