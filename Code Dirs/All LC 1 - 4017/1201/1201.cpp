// Link: https://leetcode.com/problems/ugly-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lcmAB = lcm((long long)a, (long long)b);
        long long lcmAC = lcm((long long)a, (long long)c);
        long long lcmBC = lcm((long long)b, (long long)c);
        long long lcmABC = lcm(lcmAB, (long long)c);

        long long lo = 1, hi = 2e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = mid/a + mid/b + mid/c - mid/lcmAB - mid/lcmAC - mid/lcmBC + mid/lcmABC;
            if (count < n) lo = mid + 1;
            else hi = mid;
        }
        return (int)lo;
    }

private:
    long long lcm(long long x, long long y) {
        return x / __gcd(x, y) * y;
    }
};
