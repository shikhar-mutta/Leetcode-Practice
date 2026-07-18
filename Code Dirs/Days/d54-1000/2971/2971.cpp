// Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    //   Approach:
    //   1. Calculate the sum of all elements in the array.
    //   2. Iterate through the array from the last element to the third element.
    //   3. For each element, call the findSolution function to check if a valid polygon can be formed with the current element as the largest side.
    //   4. If a valid polygon can be formed, return the sum of the sides as the largest perimeter.
    //   5. If no valid polygon can be formed, return -1.
    //   6. The findSolution function finds the maximum element in the subarray and checks if the sum of the other two sides is greater than the maximum side.
    long long largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();

        // Pre-calculate sum
        long sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        for (int i = n - 1; i > 1; --i)
        {
            long ans = findSolution(nums, i, sum);
            sum -= nums[i]; // Reduce maximum element
            if (ans != -1)
                return ans;
        }
        return -1;
    }

    long findSolution(vector<int> &nums, int end, long sum)
    {
        int maxIndex = 0;
        for (int i = 0; i <= end; ++i)
        {
            if (nums[maxIndex] < nums[i])
                maxIndex = i;
        }

        // Move maximum to end
        swap(nums[maxIndex], nums[end]);

        if (sum > 2 * nums[end])
            return sum;
        return -1;
    }
};