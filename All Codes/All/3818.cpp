// Link: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: scan from the right and find the first position where nums[i] >= nums[i+1]; that position is the answer.
class Solution
{
public:
    int minimumPrefixLength(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= nums[i + 1])
                return i + 1;
        }
        return 0;
    }
};