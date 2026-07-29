// Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: sliding window, shrink from left while sum*len >= k, add window size each step.
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0, ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
