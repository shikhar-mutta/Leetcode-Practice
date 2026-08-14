// Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long sumDiff = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sumDiff += diff[i];
        }
        long long k = k1 + k2;
        if (sumDiff <= k) return 0;

        long long lo = 0, hi = *max_element(diff.begin(), diff.end());
        auto cost = [&](long long m) {
            long long total = 0;
            for (long long d : diff) total += max(0LL, d - m);
            return total;
        };
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cost(mid) <= k) hi = mid;
            else lo = mid + 1;
        }
        long long m = lo;
        long long costM = cost(m);
        long long leftover = k - costM;

        long long sumSq = 0;
        long long countAtM = 0;
        for (long long d : diff) {
            if (d < m) sumSq += d * d;
            else countAtM++;
        }
        long long reducedCount = min(leftover, countAtM);
        sumSq += reducedCount * (m - 1) * (m - 1);
        sumSq += (countAtM - reducedCount) * m * m;
        return sumSq;
    }
};
