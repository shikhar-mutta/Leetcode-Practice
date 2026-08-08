// Link: https://leetcode.com/problems/find-and-replace-in-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + sum(len)) SC: O(n)
// Approach: sort replacement operations by index; scan s left to right, checking at each position whether a pending operation's source matches starting there, applying the replacement if so and skipping the matched length.
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){ return indices[a] < indices[b]; });

        string res;
        int i = 0, m = s.size();
        int oi = 0;
        while (i < m) {
            if (oi < n && indices[order[oi]] == i) {
                int idx = order[oi];
                string& src = sources[idx];
                if (s.compare(i, src.size(), src) == 0) {
                    res += targets[idx];
                    i += src.size();
                    oi++;
                    continue;
                }
                oi++;
            }
            res += s[i];
            i++;
        }
        return res;
    }
};
