// Link: https://leetcode.com/problems/count-special-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits^2), SC: O(digits)
// Approach: digit DP. Count all-distinct-digit numbers with fewer digits than n via permutation
// formula, then walk digits of n tight, counting valid completions at each position.
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.size();
        int ans = 0;

        // numbers with fewer digits (1..len-1 digits), first digit 1-9, rest distinct from remaining 9
        for (int L = 1; L < len; L++) {
            int cnt = 9;
            int avail = 9;
            for (int i = 1; i < L; i++) { cnt *= avail; avail--; }
            ans += cnt;
        }

        // same length as n, tight prefix
        vector<int> used(10, 0);
        for (int i = 0; i < len; i++) {
            int d = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int v = start; v < d; v++) {
                if (used[v]) continue;
                int avail = 10 - (i + 1);
                int cnt = 1;
                int remainingPositions = len - i - 1;
                for (int k = 0; k < remainingPositions; k++) cnt *= (avail - k);
                ans += cnt;
            }
            if (used[d]) break;
            used[d] = 1;
            if (i == len - 1) ans += 1; // n itself is special
        }

        return ans;
    }
};
