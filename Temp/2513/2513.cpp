// Link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l = lcm((long long)divisor1, (long long)divisor2);

        long long lo = 1, hi = 2e10;
        while (lo < hi) {
            long long m = lo + (hi - lo) / 2;
            long long avail1 = m - m / divisor1;
            long long avail2 = m - m / divisor2;
            long long availBoth = m - m / l;
            bool ok = avail1 >= uniqueCnt1 && avail2 >= uniqueCnt2 &&
                      availBoth >= (long long)uniqueCnt1 + uniqueCnt2;
            if (ok) hi = m;
            else lo = m + 1;
        }
        return (int)lo;
    }
};
