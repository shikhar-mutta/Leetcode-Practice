// Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 1, hi = (long long)ranks[0] * cars * cars;
        for (int r : ranks) hi = min(hi, (long long)r * cars * cars);

        auto canRepair = [&](long long t) {
            long long total = 0;
            for (int r : ranks) {
                long long cnt = (long long)sqrt((double)t / r);
                while (cnt > 0 && cnt * cnt * r > t) cnt--;
                while ((cnt+1) * (cnt+1) * r <= t) cnt++;
                total += cnt;
            }
            return total >= cars;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canRepair(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
