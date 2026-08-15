// Link: https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int best = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            bool valid = true;
            for (int i = 0; i < n && valid; i++) {
                if (!((mask >> i) & 1)) continue; // i is bad, statements ignored
                for (int j = 0; j < n && valid; j++) {
                    if (statements[i][j] == 2) continue;
                    int actual = (mask >> j) & 1;
                    if (statements[i][j] != actual) valid = false;
                }
            }
            if (valid) best = max(best, __builtin_popcount(mask));
        }
        return best;
    }
};
