// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        // Remove consecutive duplicates.
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int count = 0;
        for (int i = 1; i < (int)nums.size() - 1; ++i)
            if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ||
                (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]))
                count++;
        return count;
    }
};
