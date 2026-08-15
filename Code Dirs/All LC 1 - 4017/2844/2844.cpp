// Link: https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ans = n; // fallback: delete everything -> "0"
        vector<string> patterns = {"00", "25", "50", "75"};
        for (auto& pat : patterns) {
            int j = -1;
            for (int idx = n - 1; idx >= 0; idx--) {
                if (num[idx] == pat[1]) { j = idx; break; }
            }
            if (j == -1) continue;
            int i = -1;
            for (int idx = j - 1; idx >= 0; idx--) {
                if (num[idx] == pat[0]) { i = idx; break; }
            }
            if (i == -1) continue;
            int del = (n - 1 - j) + (j - i - 1);
            ans = min(ans, del);
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            if (num[idx] == '0') { ans = min(ans, n - 1); break; }
        }
        return ans;
    }
};
