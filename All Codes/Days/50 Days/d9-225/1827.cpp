// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), tar, op = 0; // Initialize the count of operations
        for (int i = 1; i < n; i++)
        { // Check if the current element is less than or equal to the previous element
            if (nums[i - 1] + 1 <= nums[i])
                continue;
            else
            { // If the current element is not greater than the previous element, we need to perform operations
                op += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        // Return the total count of operations needed to make the array strictly increasing
        return op;
    }
};
