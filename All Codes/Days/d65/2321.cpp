// Link: https://leetcode.com/problems/maximum-score-of-spliced-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Kadane's algorithm to find the maximum subarray sum of the difference array (b[i] - a[i]) and add it to the sum of array a. Repeat the process by swapping a and b, and return the maximum of the two results.
class Solution
{
public:
    int score(vector<int> &a, vector<int> &b)
    {
        int runningSum = 0, maxi = 0;
        int sum = accumulate(a.begin(), a.end(), 0);

        for (int i = 0; i < a.size(); i++)
        {
            runningSum += b[i] - a[i];
            if (runningSum < 0)
                runningSum = 0;
            maxi = max(maxi, runningSum);
        }

        return sum + maxi;
    }

    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        return max(score(nums1, nums2), score(nums2, nums1));
    }
};