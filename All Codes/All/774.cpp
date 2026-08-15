// Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(range/eps)) SC: O(1)
// Approach: binary search on the answer (max distance). Feasibility check: for a candidate max distance D, count total additional stations needed across all gaps as sum(ceil(gap/D) - 1); feasible if total <= k.
class Solution {
    bool feasible(vector<int>& stations, int k, double d) {
        long long needed = 0;
        for (int i = 1; i < (int)stations.size(); i++) {
            double gap = stations[i] - stations[i-1];
            needed += (long long)ceil(gap / d) - 1;
        }
        return needed <= k;
    }
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0, hi = 1e8;
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2;
            if (feasible(stations, k, mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};
