// Link: https://leetcode.com/problems/minimum-factorization/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: greedily divide n by the largest digit (9 down to 2) that evenly divides it, collecting digits from least significant; if leftover n > 1 after all divisions no solution exists (return 0). Build result from collected digits (smallest number = digits sorted ascending, since we peeled from largest divisors giving smallest last).
class Solution {
public:
    int smallestFactorization(int n) {
        if (n < 2) return n;
        vector<int> digits;
        for (int d = 9; d >= 2; d--) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }
        if (n != 1) return 0;
        sort(digits.begin(), digits.end());
        long long res = 0;
        for (int d : digits) {
            res = res * 10 + d;
            if (res > INT_MAX) return 0;
        }
        return (int)res;
    }
};
