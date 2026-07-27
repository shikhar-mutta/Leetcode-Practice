// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(answer * log(answer)) SC: O(1)
// Approach: brute force upward from n, compute digit product of each
// candidate, return first one whose digit product is divisible by t
// (a 0 digit gives product 0, which is divisible by any t).
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int prod = 1;
            for (int x = i; x > 0; x /= 10) prod *= x % 10;
            if (prod % t == 0) return i;
        }
    }
};
