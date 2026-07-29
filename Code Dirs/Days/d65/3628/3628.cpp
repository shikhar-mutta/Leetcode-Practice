// Link: https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> prefixL(n + 1, 0), suffixT(n + 2, 0);
        for (int i = 0; i < n; i++) prefixL[i+1] = prefixL[i] + (s[i] == 'L');
        for (int i = n - 1; i >= 0; i--) suffixT[i] = suffixT[i+1] + (s[i] == 'T');

        long long baseline = 0, gainL = 0, gainT = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'C') {
                baseline += prefixL[j] * suffixT[j+1];
                gainL += suffixT[j+1];
                gainT += prefixL[j];
            }
        }

        long long gainC = 0;
        for (int p = 0; p <= n; p++) gainC = max(gainC, prefixL[p] * suffixT[p]);

        return baseline + max({gainL, gainT, gainC});
    }
};
