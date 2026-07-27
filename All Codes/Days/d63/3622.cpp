// Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: compute digit sum and digit product, check n is divisible
// by their sum.
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        for (int x = n; x > 0; x /= 10) { sum += x % 10; prod *= x % 10; }
        return n % (sum + prod) == 0;
    }
};
