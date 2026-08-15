// Link: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> removed(n, false);
        vector<vector<int>> stacks(26);
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
                stacks[s[i]-'a'].push_back(i);
            }
        }
        string res;
        for (int i = 0; i < n; i++) if (!removed[i]) res += s[i];
        return res;
    }
};
