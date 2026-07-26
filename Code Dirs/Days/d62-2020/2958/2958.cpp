// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – each element is added to and removed from the window at most once
// SC: O(n) – frequency map holds at most n distinct values
// Approach: Sliding window. Expand hi; if nums[hi] count is already k,
// adding it would violate the constraint. Increment its count, then shrink
// lo until the duplicate of nums[hi] exits the window (inner while loop
// removes elements one by one until the offending value is popped out).
// Update result only when the window is valid (count < k before adding).
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        int result = 0, lo = 0, hi = 0;
        while (hi < nums.size()) {
            auto& c = counter[nums[hi]];
            if (c < k) {
                result = max(result, (hi + 1) - lo);
                c++;
            } else {
                c++;
                int out = nums[lo];
                counter[out]--;
                lo++;
                while (out != nums[hi]) {
                    out = nums[lo];
                    counter[out]--;
                    lo++;
                }
            }
            hi++;
        }
        return result;
    }
};
