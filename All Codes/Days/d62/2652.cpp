// Link: https://leetcode.com/problems/sum-multiples/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) — walking each of 3/5/7/15/21/35/105's multiples up to n
// SC: O(1)
// Approach: inclusion-exclusion over the three divisors (3, 5, 7): sum
// multiples of each singly, subtract multiples of each pairwise LCM (15, 21,
// 35) to remove double-counted overlaps, then add back multiples of the
// triple LCM (105) that got subtracted out three times.
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 3; i <= n; i = i + 3) {
            sum = sum + i;
        }
        for (int i = 5; i <= n; i = i + 5) {
            sum = sum + i;
        }
        for (int i = 7; i <= n; i = i + 7) {
            sum = sum + i;
        }
        for (int i = 15; i <= n; i = i + 15) {
            sum = sum - i;
        }
        for (int i = 21; i <= n; i = i + 21) {
            sum = sum - i;
        }
        for (int i = 35; i <= n; i = i + 35) {
            sum = sum - i;
        }
        for (int i = 105; i <= n; i = i + 105) {
            sum = sum + i;
        }
        return sum;
    }
};
