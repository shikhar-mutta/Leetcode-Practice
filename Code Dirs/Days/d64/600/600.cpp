// Link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log n)  SC: O(log n)
// Approach: precompute fib[i] = count of i-bit binary strings with no
// consecutive 1's (Fibonacci-like). Scan n's bits from the highest down;
// whenever a '1' bit is seen, add fib[bitsRemaining] for choosing 0 at
// this position (covers all smaller completions), and stop early if two
// consecutive 1's are seen in n itself (everything from here is valid).
class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(32, 0);
        fib[0] = 1; fib[1] = 2;
        for (int i = 2; i < 32; i++) fib[i] = fib[i - 1] + fib[i - 2];

        int ans = 0;
        int prevBit = 0;
        for (int i = 30; i >= 0; i--) {
            if ((n >> i) & 1) {
                ans += fib[i];
                if (prevBit == 1) return ans; // two consecutive 1's found
                prevBit = 1;
            } else {
                prevBit = 0;
            }
        }
        return ans + 1; // +1 for n itself (no consecutive ones found)
    }
};
