// Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * len)  SC: O(1)
// Approach: for each string, check if it is NOT a subsequence of any other
// string in the list; among qualifying candidates, take the longest
class Solution {
    bool isSubsequence(const string& s, const string& t) {
        int i = 0;
        for (char c : t) {
            if (i < (int)s.size() && s[i] == c) i++;
        }
        return i == (int)s.size();
    }

public:
    int findLUSlength(vector<string>& strs) {
        int best = -1;
        for (int i = 0; i < (int)strs.size(); i++) {
            bool uncommon = true;
            for (int j = 0; j < (int)strs.size(); j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) { uncommon = false; break; }
            }
            if (uncommon) best = max(best, (int)strs[i].size());
        }
        return best;
    }
};
