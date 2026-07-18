// Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    { // Create a result vector to store the squares of the numbers
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;     // Initialize two pointers, one at the beginning and one at the end of the array
        for (int i = nums.size() - 1; i >= 0; i--) // Iterate through the array from the end to the beginning
        {
            if (abs(nums[left]) > abs(nums[right])) // If the absolute value of the left pointer is greater than the absolute value of the right pointer, we can square the left pointer and move it to the right
            {
                result[i] = nums[left] * nums[left]; // Square the left pointer and move it to the right
                left++;
            }
            else
            {
                result[i] = nums[right] * nums[right]; // Square the right pointer and move it to the left
                right--;
            }
        }
        return result; // Return the result vector containing the squares of the numbers in sorted order
    }
};
