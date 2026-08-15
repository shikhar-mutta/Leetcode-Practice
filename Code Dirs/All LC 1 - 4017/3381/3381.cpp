// Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        vector<long long> minAtResidue(k, LLONG_MAX);
        minAtResidue[0] = prefix[0]; // index 0

        long long best = LLONG_MIN;
        for (int j = 1; j <= n; j++) {
            int r = j % k;
            if (minAtResidue[r] != LLONG_MAX) {
                best = max(best, prefix[j] - minAtResidue[r]);
            }
            minAtResidue[r] = min(minAtResidue[r], prefix[j]);
        }
        return best;
    }
};
