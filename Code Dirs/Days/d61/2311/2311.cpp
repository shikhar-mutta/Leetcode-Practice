// Link: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: all zeros are always worth keeping (they contribute nothing to
// the value regardless of position, so they never hurt). For the ones,
// scan right to left assigning each candidate 1 the bit weight it would
// have based on its distance from the end of the string (2^(number of
// characters after it)), and greedily accept it if the running value
// (using only accepted 1s so far) stays <= k - a 1 closer to the end
// always costs less than one further left, so processing rightmost-first
// and taking every affordable one is optimal.
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = count(s.begin(), s.end(), '0');
        long long value = 0;
        int ones = 0;
        int bit = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (bit < 63 && value + (1LL << bit) <= k) {
                    value += (1LL << bit);
                    ++ones;
                }
            }
            ++bit; // each position further left is a higher bit
        }
        return zeros + ones;
    }
};
