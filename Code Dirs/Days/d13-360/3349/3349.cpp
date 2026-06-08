// Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        const int n = nums.size();
        const int *data = nums.data(); // raw pointer, avoids bounds-check overhead
        int runLen = 1, prev = 0;
        const int twoK = 2 * k; // hoist out of loop

        for (int i = 1; i < n; i++)
        {
            if (data[i] > data[i - 1])
            {
                runLen++;
            }
            else
            {
                prev = runLen;
                runLen = 1;
            }

            if (runLen >= twoK || (prev >= k && runLen >= k))
            {
                return true;
            }
        }

        return false;
    }
};