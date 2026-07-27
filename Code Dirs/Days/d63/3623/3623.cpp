// Link: https://leetcode.com/problems/count-number-of-trapezoids-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: group points by y-coordinate; each group of size cnt yields
// C(cnt,2) distinct horizontal segments (candidate parallel bases). Any
// two such segments from DIFFERENT y-levels form a valid trapezoid (two
// segments on the same line can't). Total = sum over unordered pairs of
// distinct y-levels of segCount[y1]*segCount[y2], computed via
// (S^2 - sum(segCount^2)) / 2 under the modulus.
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> cntByY;
        for (auto& p : points) cntByY[p[1]]++;

        long long S = 0, sumSq = 0;
        for (auto& [y, cnt] : cntByY) {
            long long seg = cnt * (cnt - 1) / 2 % MOD;
            S = (S + seg) % MOD;
            sumSq = (sumSq + seg * seg) % MOD;
        }

        long long inv2 = (MOD + 1) / 2;
        long long ans = ((S * S % MOD - sumSq + MOD) % MOD) * inv2 % MOD;
        return (int)ans;
    }
};
