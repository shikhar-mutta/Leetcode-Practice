// Link: https://leetcode.com/problems/longest-alternating-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int best = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] - nums[i] != 1) continue;
            int j = i + 1;
            int expected = 1;
            while (j < n && nums[j] - nums[j-1] == expected) {
                j++;
                expected = -expected;
            }
            best = max(best, j - i);
        }
        return best;
    }
};
