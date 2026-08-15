// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: incrementing n-1 elements by 1 is equivalent to decrementing 1
// element by 1 relative to the rest; total moves = sum(nums) - n*min(nums)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = INT_MAX;
        for (int x : nums) { sum += x; mn = min(mn, x); }
        return (int)(sum - (long long)mn * nums.size());
    }
};
