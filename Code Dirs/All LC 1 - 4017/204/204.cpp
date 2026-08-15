// Link: https://leetcode.com/problems/count-primes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log log n)  SC: O(n)
// Approach: Sieve of Eratosthenes, count entries left marked prime
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> composite(n, false);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (composite[i]) continue;
            count++;
            for (long long j = (long long)i * i; j < n; j += i) composite[j] = true;
        }
        return count;
    }
};
