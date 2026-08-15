// Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long total = 0, run = 0;
        for (char c : s) {
            if (c == '1') { run++; total = (total + run) % MOD; }
            else run = 0;
        }
        return (int)total;
    }
};
