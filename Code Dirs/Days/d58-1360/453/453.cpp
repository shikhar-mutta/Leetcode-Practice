// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array nums.
    // SC: O(1) since we are using a constant amount of extra space.
    // Approach:
    //   1. We can find the minimum value in the array nums.
    //   2. Then, we can calculate the total sum of the elements in the array nums.
    //   3. Finally, we can return the difference between the total sum and the product of the minimum value and the length of the array nums, which gives us the minimum number of moves required to make all elements equal.
    int minMoves(vector<int> &nums)
    {
        long long sum = 0;
        int minVal = nums[0];
        for (int x : nums)
        {
            sum += x;
            minVal = min(minVal, x);
        }
        return (int)(sum - (long long)minVal * nums.size());
    }
};
