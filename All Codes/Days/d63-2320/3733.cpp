// Link: https://leetcode.com/problems/minimum-time-to-complete-all-deliveries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(maxT)) SC: O(1)
// Approach: binary search on total time T. Within [1,T], hours split into:
// only-drone1-available (multiple of r2, not r1), only-drone2-available,
// both-available (multiple of neither), neither-available (multiple of
// lcm). Drone i first uses its exclusive slots, then draws remaining need
// from the shared "both" pool; feasible iff the two remaining needs sum to
// at most the shared pool size.
class Solution
{
    bool feasible(long long T, long long d1, long long d2, long long r1, long long r2, long long lcm)
    {
        long long f1 = T / r1, f2 = T / r2, fl = T / lcm;
        long long o1 = f2 - fl;         // multiples of r2 not r1
        long long o2 = f1 - fl;         // multiples of r1 not r2
        long long b = T - f1 - f2 + fl; // neither
        long long need1 = max(0LL, d1 - o1);
        long long need2 = max(0LL, d2 - o2);
        return need1 + need2 <= b;
    }

public:
    long long minimumTime(vector<int> &d, vector<int> &r)
    {
        long long d1 = d[0], d2 = d[1], r1 = r[0], r2 = r[1];
        long long g = __gcd(r1, r2);
        long long lcm = r1 / g * r2;
        long long lo = 1, hi = 4e9;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid, d1, d2, r1, r2, lcm))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
