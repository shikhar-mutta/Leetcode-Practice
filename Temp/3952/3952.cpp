// Link: https://leetcode.com/problems/maximum-total-value-of-covered-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. Start from the end of the array and iterate backwards.
    //  2. If the current index is covered (s[i] == '1'),
    //     find the contiguous segment of covered indices and calculate the sum of their values.
    //  3. Keep track of the minimum value in the segment and subtract it from the sum to maximize the total value.
    //  4. If the current index is not covered (s[i] == '0'), simply move to the next index.
    //  5. Continue this process until all indices have been processed, and return the total value.
    long long maxTotal(vector<int> &nums, string s)
    {
        int n = nums.size();
        long long sum = 0;
        int i = n - 1;
        while (i >= 0)
        {
            int j = -1;
            long long curr = 0;
            int mini = INT_MAX;
            if (s[i] == '1')
            {
                j = i;
                mini = min(mini, nums[i]);
                curr += nums[i];
                i--;
                while (i < n - 1 && i >= 0 && s[i] == '1' && s[i + 1] == '1')
                {
                    curr += nums[i];
                    mini = min(mini, nums[i]);
                    i--;
                }
            }
            if (j == -1)
            {
                i--;
                continue;
            }
            if (i >= 0)
            {
                curr += nums[i];
                mini = min(mini, nums[i]);
                sum += curr - mini;
            }
            else
                sum += curr;

            i--;
        }
        return sum;
    }
};