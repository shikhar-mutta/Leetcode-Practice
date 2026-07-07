// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(n) = O(n)
    // SC: O(1)
    //  Approach: The optimal solution is to move all elements to the median of the array.
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        long long median = nums[n / 2], moves = 0;
        for (int x : nums)
            moves += llabs(x - median);
        return moves;
    }
};
