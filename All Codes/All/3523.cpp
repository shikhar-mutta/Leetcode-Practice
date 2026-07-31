// Link: https://leetcode.com/problems/make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: iterate through the array and keep track of the maximum element seen so far.
//  If the current element is greater than or equal to the maximum element seen so far, increment the count and update the maximum element seen so far.
class Solution
{
public:
    int maximumPossibleSize(vector<int> &nums)
    {
        int t = nums[0];
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (t <= nums[i])
            {
                c++;
                t = nums[i];
            }
        }
        return c;
    }
};