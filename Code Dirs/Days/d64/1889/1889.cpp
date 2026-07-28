// Link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n + sum(boxes_i)) log n)  SC: O(n)
// Approach: sort packages, build prefix sum. For each supplier, sort its box
// sizes; for each box size find how many not-yet-covered packages fit (binary
// search) and add box_size * count_of_those_packages - their_sum to wasted
// space, tracking prefix pointer. Discard suppliers that can't cover the
// largest package.
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const long long MOD = 1e9 + 7;
        sort(packages.begin(), packages.end());
        int n = packages.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + packages[i];
        long long total = prefix[n];
        int maxPkg = packages[n-1];

        long long best = LLONG_MAX;
        for (auto boxSet : boxes) {
            sort(boxSet.begin(), boxSet.end());
            if (boxSet.back() < maxPkg) continue;
            long long used = 0;
            int prevIdx = 0;
            for (int b : boxSet) {
                int idx = upper_bound(packages.begin(), packages.end(), b) - packages.begin();
                if (idx > prevIdx) {
                    long long cnt = idx - prevIdx;
                    long long sum = prefix[idx] - prefix[prevIdx];
                    used += (long long)b * cnt - sum;
                    prevIdx = idx;
                }
            }
            best = min(best, used);
        }
        if (best == LLONG_MAX) return -1;
        return (int)(best % MOD);
    }
};
