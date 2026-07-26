// Link: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: walk 1..n, bucketing each into the divisible-by-m sum or the
// non-divisible sum, then return their difference.
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) num2 += i;
            else num1 += i;
        }
        return num1 - num2;
    }
};
