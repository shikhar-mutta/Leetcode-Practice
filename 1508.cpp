// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + nlog(maxSum) + n) = O(nlog(maxSum))
// SC: O(n)
// Approach:
//  1. Use binary search to find the kth smallest subarray sum.
//  2. Use prefix sums to calculate the sum of all subarrays <= kth smallest sum
class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;

    // Returns the sum of the first k smallest subarray sums.
    long long firstKSum(vector<int> &nums, int k)
    {
        if (k <= 0)
            return 0;

        int n = nums.size();

        // Prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        // Prefix of prefix sums
        vector<long long> prefixPrefix(n + 2, 0);
        for (int i = 0; i <= n; i++)
            prefixPrefix[i + 1] = prefixPrefix[i] + prefix[i];

        long long low = *min_element(nums.begin(), nums.end());
        long long high = prefix[n];

        // Binary search kth smallest sum
        while (low < high)
        {
            long long mid = (low + high) / 2;

            long long cnt = 0;
            int left = 0;

            for (int right = 0; right < n; right++)
            {
                while (prefix[right + 1] - prefix[left] > mid)
                    left++;

                cnt += right - left + 1;
            }

            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }

        long long kth = low;

        // Calculate sum of all subarrays <= kth
        long long totalSum = 0;
        long long count = 0;

        int left = 0;

        for (int right = 0; right < n; right++)
        {

            while (prefix[right + 1] - prefix[left] > kth)
                left++;

            count += right - left + 1;

            totalSum += (long long)(right - left + 1) * prefix[right + 1] -
                        (prefixPrefix[right + 1] - prefixPrefix[left]);
        }

        // Remove extra occurrences equal to kth
        totalSum -= (count - k) * kth;

        return totalSum;
    }

    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        return (firstKSum(nums, right) - firstKSum(nums, left - 1) + MOD) % MOD;
    }
};