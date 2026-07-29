// Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log(sum)), SC: O(N)
// Approach: binary search the answer (min power target). Feasibility check: sliding window sum
// gives base power per city; greedily, whenever a city falls short, place all needed extra
// stations as far right as possible (i+r) to cover the most future cities, tracked via a diff array.
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> base(n, 0);
        long long windowSum = 0;
        for (int i = 0; i < min((long long)r + 1, (long long)n); i++) windowSum += stations[i];
        for (int i = 0; i < n; i++) {
            base[i] = windowSum;
            int addIdx = i + r + 1;
            int removeIdx = i - r;
            if (addIdx < n) windowSum += stations[addIdx];
            if (removeIdx >= 0) windowSum -= stations[removeIdx];
        }

        auto feasible = [&](long long target) -> bool {
            vector<long long> power = base;
            vector<long long> diff(n + 1, 0);
            long long extra = 0;
            long long budget = k;
            for (int i = 0; i < n; i++) {
                extra += diff[i];
                long long cur = power[i] + extra;
                if (cur < target) {
                    long long need = target - cur;
                    budget -= need;
                    if (budget < 0) return false;
                    extra += need;
                    int placeEnd = min(n, i + 2*r + 1);
                    diff[placeEnd] -= need;
                }
            }
            return true;
        };

        long long lo = *min_element(base.begin(), base.end());
        long long hi = base[0];
        for (long long b : base) hi = max(hi, b);
        hi += k;
        long long ans = lo;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
