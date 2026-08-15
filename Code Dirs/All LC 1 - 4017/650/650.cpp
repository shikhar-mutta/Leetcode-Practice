// Link: https://leetcode.com/problems/2-keys-keyboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) SC: O(1)
// Approach: min operations equals sum of prime factors of n (each prime factor p requires a copy+paste block of p operations).
class Solution {
public:
    int minSteps(int n) {
        int ops = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                ops += d;
                n /= d;
            }
        }
        return ops;
    }
};
