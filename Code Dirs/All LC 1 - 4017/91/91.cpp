// Link: https://leetcode.com/problems/decode-ways/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: DP with two rolling values; a '0' can only be decoded as part of a two-digit code (10 or 20)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        int prev2 = 1, prev1 = 1;
        for (int i = 1; i < n; i++) {
            int cur = 0;
            if (s[i] != '0') cur += prev1;
            int two = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26) cur += prev2;
            if (cur == 0) return 0;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
