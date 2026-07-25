// Link: https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the number of valid ways to place non-adjacent houses on ONE
// side of the street of length n follows a Fibonacci-like recurrence
// (ways(i) = ways(i-1) + ways(i-2), each position either left empty or
// occupied with the previous forced empty), computed iteratively. The two
// sides of the street are independent, so the total is ways(n) squared,
// mod 1e9+7.
class Solution {
public:
    int countHousePlacements(int n) {
        long long MOD = 1e9 + 7;

        long long prev2 = 1;
        long long prev1 = 2;

        if (n == 1) {
            return (prev1 * prev1) % MOD;
        }
        long long current = 0;
        for (int i = 2; i <= n; ++i) {
            current = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = current;
        }
        long long total_ways = (current * current) % MOD;

        return total_ways;
    }
};
