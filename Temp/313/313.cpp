// Link: https://leetcode.com/problems/super-ugly-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k)  SC: O(n + k)
// Approach: DP with one pointer per prime, ugly[i] = min over primes of
// ugly[ptr[p]] * p, advance all pointers that produced the min
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> ugly(n);
        ugly[0] = 1;
        vector<int> ptr(k, 0);

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;
            for (int p = 0; p < k; p++) next = min(next, ugly[ptr[p]] * primes[p]);
            ugly[i] = next;
            for (int p = 0; p < k; p++) if (ugly[ptr[p]] * primes[p] == next) ptr[p]++;
        }
        return (int)ugly[n - 1];
    }
};
