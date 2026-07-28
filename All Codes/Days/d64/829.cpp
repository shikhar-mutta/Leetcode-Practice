// Link: https://leetcode.com/problems/consecutive-numbers-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sqrt(n))  SC: O(1)
// Approach: a run of k consecutive integers starting at a>=1 sums to
// k*a + k*(k-1)/2 = n, so k must divide (n - k*(k-1)/2) evenly with a
// positive quotient. Try k = 1,2,3,... while k*(k+1)/2 <= n, counting
// valid k's.
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (long long k = 1; k * (k + 1) / 2 <= n; k++) {
            long long rem = n - k * (k - 1) / 2;
            if (rem % k == 0) count++;
        }
        return count;
    }
};
