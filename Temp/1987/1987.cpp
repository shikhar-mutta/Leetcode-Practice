// Link: https://leetcode.com/problems/number-of-unique-good-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

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
                end0 = (end0 + end1) % MOD;
                hasZero = true;
            }
        }
        return (int)((end0 + end1 + (hasZero ? 1 : 0)) % MOD);
    }
};
