// Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int best = 0, cur = 0;
        for (int x : nums) {
            if (x == maxVal) cur++;
            else cur = 0;
            best = max(best, cur);
        }
        return best;
    }
};
