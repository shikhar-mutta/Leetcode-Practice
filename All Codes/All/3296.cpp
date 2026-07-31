// Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(workers * log(maxTime)), SC: O(1)
// Approach: Binary search on total time t. A worker with rate w can reduce
// the height by x in time w*(1+2+...+x) = w*x*(x+1)/2, so within budget t
// it can contribute floor of the positive root of w*x^2+w*x-2t=0, i.e.
// (sqrt(1+8t/w)-1)/2. Sum each worker's max contribution for a given t and
// find the smallest t whose total meets mountainHeight.
class Solution {
public:
    inline static long long f(long long t, vector<int>& workerTimes) {
        long long x = 0;
        for (int w : workerTimes)
            x += (long long)((sqrt(1 + 8.0 * t / w) - 1) / 2);
        return x;
    }
    static long long minNumberOfSeconds(int mountainHeight,
                                        vector<int>& workerTimes) {
        int wz = workerTimes.size();
        if (wz == 1)
            return (long long)workerTimes[0] * mountainHeight *
                   (mountainHeight + 1) / 2;
        long long l = 1, r = 1e12 * (long long)mountainHeight / wz;
        while (l < r) {
            long long m = l + (r - l) / 2;
            long long x = f(m, workerTimes);
            if (x >= mountainHeight)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
