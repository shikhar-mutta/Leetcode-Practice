// Link: https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(1)
    int longestAlternatingSubarray(vector<int> &nums, int threshold)
    {
        int mxLen = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= threshold && nums[i] % 2 == 0)
            {
                int j = i + 1;
                while (j < n && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2)
                    j++;
                mxLen = max(mxLen, j - i);
            }
        }
        return mxLen;
    }
};
