// Link: https://leetcode.com/problems/prime-arrangements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> isComposite(n + 1, false);
        int primeCount = 0;
        for (int i = 2; i <= n; i++) {
            if (!isComposite[i]) {
                primeCount++;
                for (long long j = (long long)i * i; j <= n; j += i) isComposite[j] = true;
            }
        }
        const long long MOD = 1e9 + 7;
        long long res = 1;
        for (int i = 1; i <= primeCount; i++) res = res * i % MOD;
        for (int i = 1; i <= n - primeCount; i++) res = res * i % MOD;
        return (int)res;
    }
};
