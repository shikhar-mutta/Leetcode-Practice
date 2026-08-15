// Link: https://leetcode.com/problems/largest-subarray-length-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int bestIdx = 0;
        for (int i = 1; i <= n - k; i++) {
            if (nums[i] > nums[bestIdx]) bestIdx = i;
        }
        return vector<int>(nums.begin() + bestIdx, nums.begin() + bestIdx + k);
    }
};
