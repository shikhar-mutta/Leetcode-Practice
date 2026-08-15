// Link: https://leetcode.com/problems/longest-nice-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, mask = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (mask & nums[right]) {
                mask ^= nums[left];
                left++;
            }
            mask |= nums[right];
            best = max(best, right - left + 1);
        }
        return best;
    }
};
