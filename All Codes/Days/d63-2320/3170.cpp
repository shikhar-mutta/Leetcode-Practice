// Link: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26), SC: O(n)
// Approach: Keep a stack of indices per letter ('a'-'z'). On a non-star
// char, push its index onto its letter's stack. On a star, mark it removed
// and remove the most recent occurrence of the smallest letter that still
// has an index on its stack (scanning 'a' to 'z' finds the smallest
// available). Finally rebuild the string from unremoved indices.
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> stacks(26);
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removed[i] = true;
                for (int c = 0; c < 26; c++) {
                    if (!stacks[c].empty()) {
                        int idx = stacks[c].back();
                        stacks[c].pop_back();
                        removed[idx] = true;
                        break;
                    }
                }
            } else {
                stacks[s[i] - 'a'].push_back(i);
            }
        }

        string ans;
        for (int i = 0; i < n; i++) {
            if (!removed[i])
                ans += s[i];
        }

        return ans;
    }
};
