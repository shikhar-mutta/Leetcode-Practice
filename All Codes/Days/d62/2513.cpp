// Link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(maxAnswer)) for the binary search, O(1) per feasibility check
// SC: O(1)
// Approach: binary search the smallest maximum value x such that [1, x]
// contains enough usable numbers: numbers not divisible by d1 can go in
// array 1 (need >= uniqueCnt1 of them), numbers not divisible by d2 can
// go in array 2 (need >= uniqueCnt2 of them), and the total count of
// numbers divisible by neither (freely assignable to either array) must
// cover uniqueCnt1 + uniqueCnt2 combined.
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        long long lcm = lcmVal(divisor1, divisor2);

        long long lo = 1, hi = 1e10;
        while (lo < hi) {
            long long x = lo + (hi - lo) / 2;
            if (feasible(x, divisor1, divisor2, lcm, uniqueCnt1, uniqueCnt2))
                hi = x;
            else
                lo = x + 1;
        }
        return (int)lo;
    }

private:
    bool feasible(long long x, int d1, int d2, long long lcm, int cnt1,
                  int cnt2) {
        // numbers in [1, x] not divisible by d1: available for array 1
        long long avail1 = x - x / d1;
        // not divisible by d2: available for array 2
        long long avail2 = x - x / d2;
        // not divisible by either: shareable between the two
        long long availBoth = x - x / d1 - x / d2 + x / lcm;

        // array 1 needs cnt1 from avail1, array 2 needs cnt2 from avail2,
        // total distinct needed is cnt1 + cnt2 from the total usable pool
        long long total = x - x / lcm; // usable by at least one array
        return avail1 >= cnt1 && avail2 >= cnt2 &&
               total >= (long long)cnt1 + cnt2;
    }
    long long lcmVal(long long a, long long b) { return a / gcd(a, b) * b; }
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};
