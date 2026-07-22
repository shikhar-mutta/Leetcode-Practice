// Link: https://leetcode.com/problems/arithmetic-slices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. Initialize two variables, total and cur, to keep track of the total number of arithmetic slices and the current length of the arithmetic slice.
    //  2. Iterate through the array starting from the third element (index 2).
    //  3. For each element, check if it forms an arithmetic slice with the previous two elements by comparing the differences.
    //  4. If it does, increment cur and add it to total. If not, reset cur to 0.
    //  5. Return the total number of arithmetic slices found.
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        int total = 0, cur = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                cur++;
                total += cur;
            }
            else
            {
                cur = 0;
            }
        }
        return total;
    }
};
