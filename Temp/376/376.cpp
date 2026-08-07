// Link: https://leetcode.com/problems/wiggle-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track length of longest wiggle ending in an "up" move and one
// ending in a "down" move, update greedily as we scan
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1, down = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) up = down + 1;
            else if (nums[i] < nums[i - 1]) down = up + 1;
        }
        return max(up, down);
    }
};
