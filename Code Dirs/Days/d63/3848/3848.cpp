// Link: https://leetcode.com/problems/check-digitorial-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: a "digitorial" number equals the sum of the factorials of
// its own digits (e.g. 145 = 1! + 4! + 5!). Compute that sum and compare.
class Solution {
    int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
public:
    bool isDigitorialPermutation(int n) {
        int x = n, sum = 0;
        while (x > 0) { sum += fact[x % 10]; x /= 10; }
        return sum == n;
    }
};
