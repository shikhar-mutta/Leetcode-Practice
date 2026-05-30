// Link: https://leetcode.com/problems/sort-array-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int ind = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        return nums;
    }
};
