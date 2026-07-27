// Link: https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of digit counts) SC: O(1)
// Approach: for each number, compute (max digit - min digit). Find the
// maximum such range across all numbers, then sum every number
// achieving that maximum range.
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> ranges(nums.size());
        int best = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            int mn = 9, mx = 0;
            for (char c : to_string(nums[i])) {
                int d = c - '0';
                mn = min(mn, d);
                mx = max(mx, d);
            }
            ranges[i] = mx - mn;
            best = max(best, ranges[i]);
        }
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) if (ranges[i] == best) sum += nums[i];
        return sum;
    }
};
