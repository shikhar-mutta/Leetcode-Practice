// Link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const long long MOD = 1e9 + 7;
        sort(packages.begin(), packages.end());
        int n = packages.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + packages[i];

        long long best = LLONG_MAX;
        for (auto& supplier : boxes) {
            sort(supplier.begin(), supplier.end());
            if (supplier.back() < packages.back()) continue;

            long long total = 0;
            int prevIdx = 0;
            for (int box : supplier) {
                int idx = upper_bound(packages.begin(), packages.end(), box) - packages.begin();
                if (idx > prevIdx) {
                    long long count = idx - prevIdx;
                    long long sum = prefix[idx] - prefix[prevIdx];
                    total += (long long)box * count - sum;
                    prevIdx = idx;
                }
            }
            best = min(best, total);
        }
        if (best == LLONG_MAX) return -1;
        return (int)(best % MOD);
    }
};
