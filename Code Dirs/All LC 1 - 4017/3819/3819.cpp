// Link: https://leetcode.com/problems/rotate-non-negative-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: negative elements stay fixed in place; collect the
//  non-negative values in order, rotate that subsequence (new[i] =
//  old[(i+k) % count]), then write the rotated values back into their
//  original positions.
class Solution
{
public:
    vector<int> rotateElements(vector<int> &nums, int k)
    {
        vector<int> pos;
        for (int x : nums)
        {
            if (x >= 0)
                pos.push_back(x);
        }
        int n = pos.size();
        if (n == 0)
            return nums;
        k = k % n;
        rotate(pos.begin(), pos.begin() + k, pos.end());
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                nums[i] = pos[j];
                j++;
            }
        }
        return nums;
    }
};