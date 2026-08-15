// Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k^n) worst case, pruned heavily SC: O(n)
// Approach: sort descending; backtrack assigning each number to one of k buckets, skipping buckets with equal current sum (dedup) and buckets that would overflow target.
class Solution {
    bool backtrack(vector<int>& nums, int idx, vector<int>& buckets, int target) {
        if (idx == (int)nums.size()) return true;
        for (int i = 0; i < (int)buckets.size(); i++) {
            if (buckets[i] + nums[idx] > target) continue;
            if (i > 0 && buckets[i] == buckets[i-1]) continue;
            buckets[i] += nums[idx];
            if (backtrack(nums, idx+1, buckets, target)) return true;
            buckets[i] -= nums[idx];
            if (buckets[i] == 0) break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<int> buckets(k, 0);
        return backtrack(nums, 0, buckets, target);
    }
};
