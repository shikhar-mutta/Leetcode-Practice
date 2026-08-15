// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n; ; x++) {
            int prod = 1;
            int y = x;
            while (y > 0) { prod *= y % 10; y /= 10; }
            if (prod % t == 0) return x;
        }
    }
};
