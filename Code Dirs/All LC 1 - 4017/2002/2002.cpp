// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int full = 1 << n;
        vector<int> val(full, 0);
        for (int mask = 1; mask < full; mask++) {
            int l = 0, r = n - 1;
            bool ok = true;
            while (l < r) {
                while (l < r && !((mask >> l) & 1)) l++;
                while (l < r && !((mask >> r) & 1)) r--;
                if (l < r) {
                    if (s[l] != s[r]) { ok = false; break; }
                    l++; r--;
                }
            }
            if (ok) val[mask] = __builtin_popcount(mask);
        }
        vector<int> best = val;
        for (int mask = 1; mask < full; mask++) {
            for (int b = 0; b < n; b++) {
                if ((mask >> b) & 1) {
                    best[mask] = max(best[mask], best[mask ^ (1 << b)]);
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < full; mask++) {
            if (val[mask] > 0) {
                int comp = (full - 1) ^ mask;
                ans = max(ans, val[mask] * best[comp]);
            }
        }
        return ans;
    }
};
