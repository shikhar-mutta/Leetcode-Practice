// Link: https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> a(n, 1);
        for (int s = 0; s < k; s++) {
            for (int i = 1; i < n; i++) a[i] = (a[i] + a[i-1]) % MOD;
        }
        return (int)a[n-1];
    }
};
