// Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long moves = 0;
        int needed = nums.empty() ? 0 : nums[0];
        for (int x : nums) {
            if (x < needed) {
                moves += needed - x;
            } else {
                needed = x;
            }
            needed++;
        }
        return (int)moves;
    }
};
