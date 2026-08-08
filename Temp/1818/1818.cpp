// Link: https://leetcode.com/problems/minimum-absolute-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const long long MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sorted1 = nums1;
        sort(sorted1.begin(), sorted1.end());

        long long total = 0;
        long long maxGain = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            total += diff;

            auto it = lower_bound(sorted1.begin(), sorted1.end(), nums2[i]);
            long long best = diff;
            if (it != sorted1.end()) best = min(best, (long long)abs(*it - nums2[i]));
            if (it != sorted1.begin()) best = min(best, (long long)abs(*prev(it) - nums2[i]));
            maxGain = max(maxGain, diff - best);
        }
        return (int)((total - maxGain) % MOD);
    }
};
