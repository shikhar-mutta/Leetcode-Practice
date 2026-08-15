// Link: https://leetcode.com/problems/smallest-good-base/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log^2 n)  SC: O(1)
// Approach: for each possible digit count m (from largest to smallest, i.e.
// smallest base), binary search the base k such that (k^m - 1)/(k-1) == n
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        for (int m = 60; m >= 2; m--) {
            long long lo = 2, hi = pow(num, 1.0 / (m - 1)) + 1;
            while (lo <= hi) {
                long long k = lo + (hi - lo) / 2;
                long long sum = 0, cur = 1;
                bool overflow = false;
                for (int i = 0; i < m; i++) {
                    sum += cur;
                    if (i < m - 1) {
                        if (cur > num / k + 1) { overflow = true; break; }
                        cur *= k;
                    }
                }
                if (overflow || sum > num) { hi = k - 1; continue; }
                if (sum == num) return to_string(k);
                lo = k + 1;
            }
        }
        return to_string(num - 1);
    }
};
