// Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach: Prefix Sum
    //  1. Create a prefix sum array to store the cumulative sums of the input array.
    //  2. Define a helper function that takes the prefix sum array, lengths L and M as input and calculates the maximum sum of two non-overlapping subarrays of lengths L and M.
    //  3. Iterate through the prefix sum array to find the maximum sum of two non-overlapping subarrays by keeping track of the maximum sum of the first subarray and calculating the sum of the second subarray using the prefix sum array.
    //  4. Return the maximum sum of two non-overlapping subarrays by calling the helper function twice, once for each order of the subarrays (L first, M second and M first, L second).
    int helper(vector<int> &prefix, int L, int M)
    {
        int n = prefix.size() - 1;
        int maxL = 0, result = 0;
        for (int i = L + M; i <= n; i++)
        {
            maxL = max(maxL, prefix[i - M] - prefix[i - M - L]);
            result = max(result, maxL + prefix[i] - prefix[i - M]);
        }
        return result;
    }

    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        return max(helper(prefix, firstLen, secondLen), helper(prefix, secondLen, firstLen));
    }
};
