// Link: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array.
    // SC: O(n) for storing the prefix sum of the input array.
    // Approach:
    //  1. Calculate the prefix sum of the input array.
    //  2. Use two pointers to find the valid ranges for the second and third subarrays.
    //  3. For each valid first subarray, count the number of valid second subarrays and add to the answer.
    //  4. Return the answer modulo 10^9 + 7.
    int waysToSplit(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long ans = 0;
        int j = 1, k = 1;

        for (int i = 0; i < n - 2; i++)
        {

            // j must be at least i+1
            j = max(j, i + 1);

            // Find first j such that leftSum <= midSum
            while (j < n - 1 && prefix[j] - prefix[i] < prefix[i])
            {
                j++;
            }

            // k should never be behind j
            k = max(k, j);

            // Find first k where midSum > rightSum
            while (k < n - 1 &&
                   prefix[k] - prefix[i] <= prefix[n - 1] - prefix[k])
            {
                k++;
            }

            ans += (k - j);
            ans %= MOD;
        }

        return ans;
    }
};