// Link: https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(long long x) {
        int s = 0;
        while (x > 0) { s += x % 10; x /= 10; }
        return s;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long orig = n;
        while (digitSum(n) > target) {
            n = (n / 10 + 1) * 10;
        }
        return n - orig;
    }
};
