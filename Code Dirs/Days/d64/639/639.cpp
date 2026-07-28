// Link: https://leetcode.com/problems/decode-ways-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: standard decode-ways DP (dp[i] = ways to decode prefix of
// length i) extended to count '*' as a wildcard for digits 1-9 (single)
// or specific ranges when paired with the previous character (e.g.
// "*4" matches 14/24, "1*" matches 11-19, "2*" matches 21-26, "**"
// matches 11-19 and 21-26). Rolling variables avoid O(n) extra space.
class Solution {
public:
    int numDecodings(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        long long prev2 = 1; // dp[0]
        long long prev1;     // dp[1]
        char c0 = s[0];
        if (c0 == '*') prev1 = 9;
        else if (c0 == '0') prev1 = 0;
        else prev1 = 1;

        for (int i = 2; i <= n; i++) {
            char c1 = s[i - 2], c2 = s[i - 1];
            long long cur = 0;
            // single-digit contribution from c2
            if (c2 == '*') cur += prev1 * 9;
            else if (c2 != '0') cur += prev1;
            // two-digit contribution from c1,c2
            if (c1 == '*') {
                if (c2 == '*') cur += prev2 * 15; // 11-19,21-26 => 9+6
                else if (c2 <= '6') cur += prev2 * 2; // 1_ and 2_ both valid
                else cur += prev2; // only 1_
            } else if (c1 == '1') {
                if (c2 == '*') cur += prev2 * 9; // 11-19
                else cur += prev2;
            } else if (c1 == '2') {
                if (c2 == '*') cur += prev2 * 6; // 21-26
                else if (c2 <= '6') cur += prev2;
            }
            cur %= MOD;
            prev2 = prev1;
            prev1 = cur;
        }
        return (int)prev1;
    }
};
