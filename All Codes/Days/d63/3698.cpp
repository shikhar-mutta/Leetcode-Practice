// Link: https://leetcode.com/problems/split-array-with-minimum-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: precompute how far a strictly-increasing run extends from
// the start and how far a strictly-decreasing run extends to the end.
// For each split point i (left = nums[0..i], right = nums[i+1..n-1]),
// it's valid only if left is fully within the increasing prefix and
// right is fully within the decreasing suffix. Track the min |diff| via
// running prefix/suffix sums.
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> incOk(n, false), decOk(n, false);
        incOk[0] = true;
        for (int i = 1; i < n; i++) incOk[i] = incOk[i-1] && nums[i] > nums[i-1];
        decOk[n-1] = true;
        for (int i = n - 2; i >= 0; i--) decOk[i] = decOk[i+1] && nums[i] > nums[i+1];

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
        long long total = prefix[n];

        long long best = -1;
        for (int i = 0; i < n - 1; i++) {
            if (!incOk[i] || !decOk[i+1]) continue;
            long long leftSum = prefix[i+1];
            long long rightSum = total - leftSum;
            long long diff = llabs(leftSum - rightSum);
            if (best == -1 || diff < best) best = diff;
        }
        return best;
    }
};
