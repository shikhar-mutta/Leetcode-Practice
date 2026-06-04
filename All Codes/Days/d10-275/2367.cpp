// Link: https://leetcode.com/problems/number-of-arithmetic-triplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Brute Force with Early Stopping Condition.
    // TC: O(N^3). SC: O(1)
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((nums[j] - nums[i]) == diff) // Early Stopping Condition
                {
                    for (int k = j + 1; k < n; k++)
                        if (nums[k] - nums[j] == diff)
                        {
                            count++;
                        }
                }
        return count;
    }
};
