// Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool feasible(vector<long long>& basePower, int n, int r, long long k, long long target) {
        vector<long long> diff(n + 1, 0);
        long long added = 0;
        long long budget = k;
        for (int i = 0; i < n; i++) {
            added += diff[i];
            long long cur = basePower[i] + added;
            if (cur < target) {
                long long need = target - cur;
                if (need > budget) return false;
                budget -= need;
                added += need;
                int effectRight = min(n - 1, i + 2 * r);
                diff[effectRight + 1] -= need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stations[i];

        vector<long long> basePower(n);
        for (int i = 0; i < n; i++) {
            int lo = max(0, i - r), hi = min(n - 1, i + r);
            basePower[i] = prefix[hi+1] - prefix[lo];
        }

        long long lo = *min_element(basePower.begin(), basePower.end());
        long long hi = lo + k + accumulate(stations.begin(), stations.end(), 0LL);

        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(basePower, n, r, k, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
