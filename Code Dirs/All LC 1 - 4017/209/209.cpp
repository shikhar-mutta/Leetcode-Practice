// Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: sliding window; expand right accumulating sum, shrink left while sum still meets target
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, best = INT_MAX;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                best = min(best, right - left + 1);
                sum -= nums[left++];
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
