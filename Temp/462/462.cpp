// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: minimum total distance to a single point is achieved at the
// median; sum of absolute differences to the median
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int moves = 0;
        for (int x : nums) moves += abs(x - median);
        return moves;
    }
};
