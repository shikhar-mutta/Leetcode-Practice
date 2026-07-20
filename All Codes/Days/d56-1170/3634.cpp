// Link: https://leetcode.com/problems/minimum-removals-to-balance-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(1)
    // Approach:
    //   1. Sort the array.
    //   2. Use two pointers to find the longest subarray that satisfies the condition
    //      nums[i] <= k * nums[j] for all i < j in the subarray.
    //   3. The answer is the total number of elements minus the length of the longest subarray found.
    //   4. Return the answer.
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), best = 0, l = 0;
        for (int r = 0; r < n; r++)
        {
            while ((long long)nums[r] > (long long)k * nums[l])
                l++;
            best = max(best, r - l + 1);
        }
        return n - best;
    }
};
