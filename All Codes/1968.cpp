// Link: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // TC: O(n) where n is the number of elements in the array. We iterate through the array twice, once from left to right and once from right to left, to fix any violations of the condition.
    // SC: O(1) as we are using constant extra space.
    // Approach:
    //   1. We iterate through the array from left to right and check if the current element is equal to the average of its neighbors. If it is, we swap it with the next element to fix the violation.
    //   2. We then iterate through the array from right to left and check if the current element is equal to the average of its neighbors. If it is, we swap it with the previous element to fix the violation.
    //   3. Finally, we return the modified array.
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        // Move left to right and fix
        for (int i = 1; i < n - 1; i++)
        {

            if (2 * nums[i] == (nums[i - 1] + nums[i + 1]))
                swap(nums[i], nums[i + 1]);
        }

        // Move right to left and fix
        for (int i = nums.size() - 2; i > 0; i--)
        {

            if (2 * nums[i] == (nums[i - 1] + nums[i + 1]))
                swap(nums[i], nums[i - 1]);
        }
        return nums;
    }
};