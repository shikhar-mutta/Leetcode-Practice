// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const long long MOD = 1000000007;
        vector<long long> len(26);
        for (int i = 0; i < 26; i++) len[i] = 1;

        for (int step = 0; step < t; step++) {
            vector<long long> nlen(26);
            for (int c = 0; c < 26; c++) {
                if (c == 25) nlen[c] = (len[0] + len[1]) % MOD;
                else nlen[c] = len[c+1];
            }
            len = nlen;
        }

        long long ans = 0;
        for (char c : s) ans = (ans + len[c - 'a']) % MOD;
        return (int)ans;
    }
};
