// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-adjacent-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexicographicallySmallestString(string s) {
        int n = s.size();
        auto consecutive = [&](char a, char b) {
            int d = abs(a - b);
            return d == 1 || d == 25;
        };

        vector<vector<bool>> canRemove(n, vector<bool>(n, false));
        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                bool ok = false;
                if (consecutive(s[i], s[j])) {
                    if (len == 2) ok = true;
                    else if (canRemove[i+1][j-1]) ok = true;
                }
                if (!ok) {
                    for (int m = i + 1; m < j; m += 2) {
                        // split into [i,m] and [m+1,j], both even length
                        if (canRemove[i][m] && canRemove[m+1][j]) { ok = true; break; }
                    }
                }
                canRemove[i][j] = ok;
            }
        }

        vector<string> f(n + 1);
        f[n] = "";
        for (int i = n - 1; i >= 0; i--) {
            string best = s.substr(i, 1) + f[i+1];
            for (int j = i + 1; j < n; j += 1) {
                int len = j - i + 1;
                if (len % 2 != 0) continue;
                if (canRemove[i][j]) {
                    if (f[j+1] < best) best = f[j+1];
                }
            }
            f[i] = best;
        }

        return f[0];
    }
};
