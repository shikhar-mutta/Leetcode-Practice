// Link: https://leetcode.com/problems/minimum-time-to-make-array-sum-at-most-x/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: after T seconds with T zeroing operations, total = sum(nums1) + T*sum(nums2) minus
// the savings from the chosen zeroed indices; zeroing index i at "slot" k (1-indexed, later slots
// accrue more nums2 growth) saves nums1[i] + k*nums2[i]. To maximize savings for exactly k
// choices, assign larger nums2 values to later slots — sort ascending by nums2 and run a
// knapsack where dp[k] = max total saved choosing k indices (processed in nums2 order, so the
// current item is always eligible to be the largest-numbered slot so far).
class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] < nums2[b]; });

        vector<long long> dp(n+1, LLONG_MIN / 2);
        dp[0] = 0;
        for (int i : idx) {
            for (int k = n; k >= 1; k--) {
                if (dp[k-1] > LLONG_MIN / 4)
                    dp[k] = max(dp[k], dp[k-1] + nums1[i] + (long long)k * nums2[i]);
            }
        }

        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        for (int T = 0; T <= n; T++) {
            long long total = sum1 + (long long)T * sum2 - dp[T];
            if (total <= x) return T;
        }
        return -1;
    }
};
