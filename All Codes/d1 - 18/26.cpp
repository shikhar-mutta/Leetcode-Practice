// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int k = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i]!=nums[k])
            {
                k++;
                nums[k] = nums[i];
            }
        }
        return k + 1;
    }
};