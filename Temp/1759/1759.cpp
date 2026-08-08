// Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const long long MOD = 1e9 + 7;
        long long total = 0;
        long long run = 1;
        for (int i = 1; i <= (int)s.size(); i++) {
            if (i < (int)s.size() && s[i] == s[i-1]) {
                run++;
            } else {
                total = (total + run * (run + 1) / 2) % MOD;
                run = 1;
            }
        }
        return (int)total;
    }
};
