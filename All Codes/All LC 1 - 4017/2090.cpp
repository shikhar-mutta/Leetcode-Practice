// Link: https://leetcode.com/problems/k-radius-subarray-averages/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the input array nums.
// SC: O(n), as we are using two additional arrays left and right of size n
//  Approach:
//   1. We will create two arrays left and right of size n, where left[i] will store the sum of the elements from index 0 to i, and right[i] will store the sum of the elements from index i to n-1.
//   2. We will then iterate through the input array nums and for each index i, we will check if the k-radius subarray exists. If it does, we will calculate the sum of the elements in the k-radius subarray using the left and right arrays and divide it by (2*k + 1) to get the average. If the k-radius subarray does not exist, we will set the value at index i to -1.
//   3. Finally, we will return the modified nums array
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> right(n);
        vector<long long> left(n);

        right[0] = nums[0];
        left[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            right[i] = right[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            left[i] = left[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i - k < 0 || i + k >= n)
            {
                nums[i] = -1;
                continue;
            }
            long long sum = left[i - k] + right[i + k] - nums[i];
            if (i + 1 < n)
            {
                sum -= left[i + 1];
            }
            if (i - 1 >= 0)
            {
                sum -= right[i - 1];
            }
            nums[i] = sum / (2 * k + 1);
        }
        return nums;
    }
};