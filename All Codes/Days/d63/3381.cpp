// Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
// Approach: prefix sums grouped by index mod k. For a subarray [i+1, j]
// with length a multiple of k, i and j have the same residue mod k, so
// its sum is prefix[j] - prefix[i]. Track the minimum prefix seen so far
// per residue class and maximize prefix[j] - minPrefix[j%k] as j advances.
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        vector<long long> minPre(k, LLONG_MAX);
        long long ans = LLONG_MIN;
        for (int j = 0; j <= n; j++) {
            int r = j % k;
            if (j >= k) ans = max(ans, prefix[j] - minPre[r]);
            minPre[r] = min(minPre[r], prefix[j]);
        }
        return ans;
    }
};
