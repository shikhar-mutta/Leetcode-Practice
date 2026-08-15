// Link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(32) SC: O(32)
// Approach: precompute fib[i] = count of i-bit numbers with no two consecutive 1s. Scan n's bits from MSB; whenever a '1' bit is found, add fib[remaining bits] (count of valid numbers with 0 in this position); if previous bit was also 1, break (n itself invalid, stop). Include n+1 at the end if n's bits themselves have no consecutive ones.
class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(32);
        fib[0] = 1; fib[1] = 2;
        for (int i = 2; i < 32; i++) fib[i] = fib[i-1] + fib[i-2];
        int ans = 0;
        int prevBit = 0;
        for (int i = 30; i >= 0; i--) {
            if ((n >> i) & 1) {
                ans += fib[i];
                if (prevBit == 1) return ans;
                prevBit = 1;
            } else prevBit = 0;
        }
        return ans + 1;
    }
};
