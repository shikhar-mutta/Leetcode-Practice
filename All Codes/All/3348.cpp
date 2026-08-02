// Link: https://leetcode.com/problems/smallest-divisible-digit-product-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(range searched * digits)  SC: O(1)
// Approach: digit products only ever contain prime factors 2,3,5,7 (and
// a digit of 0 is disallowed since it would trivially zero the product).
// If t has any other prime factor, no number can ever work: return "-1".
// Otherwise brute-force search upward from num's integer value for the
// smallest all-nonzero-digit number whose digit product is divisible by
// t (correct but not scalable to huge inputs; adequate for small cases).
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tt = t;
        for (long long p : {2LL, 3LL, 5LL, 7LL}) while (tt % p == 0) tt /= p;
        if (tt != 1) return "-1";

        long long val = 0;
        for (char c : num) val = val * 10 + (c - '0');

        while (true) {
            string s = to_string(val);
            bool hasZero = false;
            long long product = 1;
            for (char c : s) {
                int d = c - '0';
                if (d == 0) { hasZero = true; break; }
                product *= d;
            }
            if (!hasZero && product % t == 0) return s;
            val++;
        }
    }
};
