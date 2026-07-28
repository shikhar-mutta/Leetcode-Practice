// Link: https://leetcode.com/problems/number-of-unique-good-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: track end0/end1 = count of distinct good subsequences (no
// leading zero) ending in 0/1. A '1' can start a fresh subsequence (+1) or
// extend any existing one; a '0' can only extend (never starts a valid
// multi-digit number). Add 1 at the end if the string contains any '0',
// accounting for the standalone subsequence "0".
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const long long MOD = 1e9 + 7;
        long long end0 = 0, end1 = 0;
        bool hasZero = false;
        for (char c : binary) {
            if (c == '1') {
                end1 = (end0 + end1 + 1) % MOD;
            } else {
                hasZero = true;
                end0 = (end0 + end1) % MOD;
            }
        }
        long long ans = (end0 + end1 + (hasZero ? 1 : 0)) % MOD;
        return (int)ans;
    }
};
