// Link: https://leetcode.com/problems/minimum-time-to-make-array-sum-at-most-x/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] < nums2[b]; });
        vector<long long> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int id = idx[i];
            for (int j = min(i + 1, n); j >= 1; j--) {
                dp[j] = max(dp[j], dp[j-1] + (long long)nums1[id] + (long long)nums2[id] * j);
            }
        }
        long long sum1 = 0, sum2 = 0;
        for (int v : nums1) sum1 += v;
        for (int v : nums2) sum2 += v;
        for (int k = 0; k <= n; k++) {
            long long total = sum1 + sum2 * k - dp[k];
            if (total <= x) return k;
        }
        return -1;
    }
};
