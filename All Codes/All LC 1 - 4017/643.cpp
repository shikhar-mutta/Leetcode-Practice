// Link: https://leetcode.com/problems/maximum-average-subarray-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long sum = 0, maxSum;
        // Use a sliding window to calculate the sum of each subarray of size 'k'
        for (int i = 0; i < k; i++)
            sum += nums[i];
        maxSum = sum;
        // Slide the window across the array, updating the sum and maxSum
        for (int i = k; i < n; i++)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        // Return the maximum average by dividing the maxSum by 'k'
        return (double)maxSum / k;
    }
};
