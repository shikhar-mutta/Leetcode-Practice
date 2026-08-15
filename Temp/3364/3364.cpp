// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                long long sum = prefix[i+len] - prefix[i];
                if (sum > 0 && sum < best) best = (int)sum;
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
