// Link: https://leetcode.com/problems/count-good-integers-on-a-grid-path/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(16 * 10 * 2)  SC: O(16 * 10 * 2)
// Approach: pad x to 16 digits placed row-major into a 4x4 grid; walking
// directions (3 D's, 3 R's) from (0,0) visits 7 cells whose row-major index
// is strictly increasing, matching left-to-right digit order. x is good iff
// the digits at those 7 visited positions are non-decreasing. answer =
// calc(r) - calc(l-1) via digit DP over 16 positions: at each "key"
// (visited) position the digit must be >= the last key digit seen;
// non-key positions are unconstrained.
class Solution {
    bool key[16];
    string s;
    long long memo[16][10][2];
    bool has[16][10][2];

    long long dfs(int pos, int last, bool lim) {
        if (pos == 16) return 1;
        if (!lim && has[pos][last][lim]) return memo[pos][last][lim];
        int start = key[pos] ? last : 0;
        int end = lim ? (s[pos] - '0') : 9;
        long long res = 0;
        for (int i = start; i <= end; i++) {
            res += dfs(pos + 1, key[pos] ? i : last, lim && (i == end));
        }
        if (!lim) { memo[pos][last][lim] = res; has[pos][last][lim] = true; }
        return res;
    }

    long long calc(long long x, string& dirs) {
        if (x < 0) return 0;
        s = to_string(x);
        while (s.size() < 16) s = "0" + s;
        memset(has, 0, sizeof(has));
        return dfs(0, 0, true);
    }
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        memset(key, false, sizeof(key));
        int row = 0, col = 0;
        key[0] = true;
        for (char c : directions) {
            if (c == 'D') row++; else col++;
            key[row * 4 + col] = true;
        }
        return calc(r, directions) - calc(l - 1, directions);
    }
};
