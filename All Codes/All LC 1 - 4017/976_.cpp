// Link: https://leetcode.com/problems/largest-perimeter-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>()); // Sort the array in descending order to check for the largest perimeter first
        for (int i = 0; i < nums.size() - 2; i++)       // Iterate through the sorted array and check if the three sides can form a triangle
        {
            // If the sum of the two smaller sides is greater than the largest side, we can form a triangle
            if (nums[i] < nums[i + 1] + nums[i + 2])
            { //  Return the perimeter of the triangle
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
