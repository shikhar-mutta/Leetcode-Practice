// Link: https://leetcode.com/problems/sum-of-floored-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + maxVal log maxVal)  SC: O(maxVal)
//  Approach: Use a frequency array to count occurrences of each number. Then, for each unique divisor d, calculate its contribution to the total sum by iterating through its multiples and counting how many numbers fall within the range of each multiple. Use a prefix sum array to efficiently count the numbers in the specified ranges. Finally, multiply the contribution by the frequency of d and accumulate it to the total sum, taking care to apply the modulo operation to prevent overflow.
class Solution
{
public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());
        // Frequency array
        vector<int> freq(maxVal + 1, 0);
        for (int num : nums)
        {
            freq[num]++;
        }
        // Prefix sum array: prefix[i] = count of numbers <= i
        vector<int> prefix(maxVal + 1, 0);
        prefix[0] = freq[0];
        for (int i = 1; i <= maxVal; i++)
        {
            prefix[i] = prefix[i - 1] + freq[i];
        }
        long long totalSum = 0;
        // For each unique divisor d
        for (int d = 1; d <= maxVal; d++)
        {
            if (freq[d] == 0)
                continue;
            long long contribution = 0;
            // For each multiple k of d
            for (int k = 1; k * d <= maxVal; k++)
            {
                int lower = k * d;
                int upper = min((k + 1) * d - 1, maxVal);
                // Count numbers in [lower, upper]
                int count = prefix[upper] - (lower > 0 ? prefix[lower - 1] : 0);
                contribution += (long long)k * count;
            }
            // Multiply by frequency of d (d appears freq[d] times as divisor)
            totalSum = (totalSum + contribution * freq[d]) % MOD;
        }
        return (int)totalSum;
    }
};
