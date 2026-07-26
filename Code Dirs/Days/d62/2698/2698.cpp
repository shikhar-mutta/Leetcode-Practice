// Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * d) amortized (d = digit count of n^2, small branching)
// SC: O(d) recursion depth
// Approach: for each i in 1..n, check whether i*i's decimal digits can be
// partitioned into contiguous substrings summing to i. canpart peels a
// SUFFIX of increasing digit-length off the current number (n%p for
// p=10,100,...), recursing on the remaining prefix with target reduced by
// that suffix's value, until the whole remaining number matches what's left
// of target (n==target) or nothing works.
class Solution {
public:
    // Helper function to check if the square can be partitioned to sum to target
    bool canpart(int n, int target) {
        // Base cases
        if (target < 0 || n > target && n == 0) return false;
        if (n == target) return true;

        // Try partitioning the number at different positions
        // Use 10, 100, 1000 etc. to split the number
        for (int p = 10; p <= n * 10; p *= 10) {
            if (canpart(n / p, target - (n % p))) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canpart(square, i)) {
                ans += square;
            }
        }
        return ans;
    }
};
