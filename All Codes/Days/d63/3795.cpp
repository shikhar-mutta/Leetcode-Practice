// Link: https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: the distinct-value sum of a window only grows (or stays
// same) as the window extends right, so a standard sliding window works:
// track per-value frequency and running distinct sum (add value when its
// frequency becomes 1, subtract when it drops to 0), shrinking from the
// left whenever the distinct sum still meets k.
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long distinctSum = 0;
        int n = nums.size();
        int best = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (++freq[nums[right]] == 1) distinctSum += nums[right];
            while (distinctSum >= k) {
                best = min(best, right - left + 1);
                if (--freq[nums[left]] == 0) distinctSum -= nums[left];
                left++;
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
