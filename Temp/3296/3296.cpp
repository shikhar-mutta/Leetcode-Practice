// Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto feasible = [&](long long T) -> bool {
            long long total = 0;
            for (int t : workerTimes) {
                // find max x such that t*x*(x+1)/2 <= T
                long long lo = 0, hi = 200000;
                while (lo < hi) {
                    long long mid = lo + (hi - lo + 1) / 2;
                    __int128 cost = (__int128)t * mid * (mid + 1) / 2;
                    if (cost <= T) lo = mid;
                    else hi = mid - 1;
                }
                total += lo;
                if (total >= mountainHeight) return true;
            }
            return total >= mountainHeight;
        };

        long long lo = 0, hi = (long long)1e18;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
