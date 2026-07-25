// Link: https://leetcode.com/problems/number-of-ways-to-select-buildings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: scan right to left, maintaining running counts of 0's and 1's
// seen so far (to the right), plus counts of "01" and "10" pairs formed so
// far (using an element at the current position as the middle of a future
// triple). At each position i: if s[i]=='0', it can be the leftmost '0' of
// a "010" (add the current "10" pair count, i.e. ones-then-zero to its
// right, to zoz) or extend a "1_" pair into "01" (zerone += one); the
// symmetric updates happen for '1'. The answer is the total triples "010"
// (zoz) plus "101" (ozo).
class Solution {
public:
    long long numberOfWays(string s) {
        long long zoz = 0, ozo = 0;
        int n = s.size();
        long long zero = 0, one = 0, zerone = 0, onezero = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zero++;
                zerone += one;
                zoz += onezero;
            } else {
                one++;
                onezero += zero;
                ozo += zerone;
            }
        }
        return zoz + ozo;
    }
};
