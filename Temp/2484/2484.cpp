// Link: https://leetcode.com/problems/count-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        const long long MOD = 1e9 + 7;
        if (n < 5) return 0;

        long long total = 0;
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                char ca = '0' + a, cb = '0' + b;
                vector<long long> pre(n, 0), suf(n, 0);

                long long countA = 0, pairs = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] == cb) pairs += countA;
                    if (s[i] == ca) countA++;
                    pre[i] = pairs;
                }

                long long countA2 = 0;
                pairs = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if (s[i] == cb) pairs += countA2;
                    if (s[i] == ca) countA2++;
                    suf[i] = pairs;
                }

                for (int k = 2; k <= n - 3; k++) {
                    total = (total + pre[k-1] * suf[k+1]) % MOD;
                }
            }
        }
        return (int)total;
    }
};
