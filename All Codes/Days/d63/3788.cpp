// Link: https://leetcode.com/problems/maximum-score-of-a-split/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: precompute suffix minimum array, then scan prefix sums left
// to right, tracking best prefixSum(i) - suffixMin(i+1) as i ranges over
// valid split points.
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sufMin(n);
        sufMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) sufMin[i] = min((long long)nums[i], sufMin[i+1]);

        long long ans = LLONG_MIN, pre = 0;
        for (int i = 0; i < n - 1; i++) {
            pre += nums[i];
            ans = max(ans, pre - sufMin[i+1]);
        }
        return ans;
    }
};
