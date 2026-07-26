// Link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the conv array
// Approach: per-element conv[i] = nums[i] + runningPrefixMax(0..i), then the
// answer is just the running prefix sum of conv.
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<int> conv;
        int maxi = nums[0];

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            conv.push_back(nums[i] + maxi);
        }

        vector<long long> ans(n);

        long long sum = conv[0];
        ans[0] = sum;

        for (int i = 1; i < n; i++) {
            sum += conv[i];
            ans[i] = sum;
        }

        return ans;
    }
};
