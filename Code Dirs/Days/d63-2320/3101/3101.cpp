// Link: https://leetcode.com/problems/count-alternating-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Scan for maximal runs where adjacent elements differ (0/1
// alternate). Every subarray within a run of length len is alternating, so
// add len*(len+1)/2 per run; jump to the next run's start after each one.
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();

        for (int start = 0; start < n; start++) {

            int end = start;

            while (end + 1 < n && nums[end] != nums[end + 1]) {
                end++;
            }

            long long len = end - start + 1;

            result += len * (len + 1) / 2;

            start = end;
        }

        return result;
    }
};
