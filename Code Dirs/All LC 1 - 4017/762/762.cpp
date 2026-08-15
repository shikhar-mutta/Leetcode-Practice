// Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((right-left) * log) SC: O(1)
// Approach: for each number, count set bits and check primality (bit counts are small, up to ~20).
class Solution {
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int n = left; n <= right; n++) {
            if (isPrime(__builtin_popcount(n))) count++;
        }
        return count;
    }
};
