// Link: https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (at most 10 iterations, since units digits cycle with period 10)
// SC: O(1)
// Approach: using c numbers each ending in digit k, their sum's units digit
// is (c*k) mod 10, and their minimum possible total is c*k (all other
// digits zero) - so c numbers can sum to exactly num iff c*k <= num and
// (c*k) mod 10 == num mod 10 (the remaining amount num - c*k, a multiple of
// 10, can always be distributed as extra tens onto the numbers, or 0 needs
// no numbers at all). Try c = 1..10 (10 is enough since digit cycles mod
// 10) and return the first that works, else -1.
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int c = 1; c <= 10; ++c) {
            if ((long long)c * k <= num && (c * k) % 10 == num % 10)
                return c;
        }
        return -1;
    }
};
