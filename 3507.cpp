// Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int opr = 0;
        auto isSorted = [&]()
        {
            int n = nums.size();
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                    return false;
            }
            return true;
        };

        while (!isSorted())
        {
            int n = nums.size();
            int minIndex = 0, minSum = INT_MAX;
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] + nums[i + 1] < minSum)
                {
                    minSum = nums[i] + nums[i + 1];
                    minIndex = i;
                }
            }
            nums.erase(nums.begin() + minIndex + 1);
            nums[minIndex] = minSum;
            opr++;
        }
        return opr;
    };
};
