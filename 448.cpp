// Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
            {
                nums[index] = -nums[index]; // Mark the number as found by negating the value at that index
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
