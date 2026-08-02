// Link: https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k)  SC: O(n)
// Approach: dpTable[j] = max sum of weights for first j elements, using i segments. Transition: either skip jth element (dpTable[j-1]) or take it (prefixSum[j]*weight + mx), where mx = max(dpTable[j'] - prefixSum[j'-1]*weight) for j' < j. Weight alternates between positive and negative based on segment index.
class Solution
{
public:
    const long long MIN = LLONG_MIN;
    long long maximumStrength(vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<long long> prefixSum(n + 1);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        std::vector<long long> dpTable(n + 1);
        for (int i = 1; i <= k; ++i)
        {
            long long prev = dpTable[i - 1];
            // skip
            dpTable[i - 1] = MIN;
            long long mx = MIN;
            long long weight = (k - i + 1) * (i % 2 ? 1 : -1);
            for (int j = i; j <= n - k + i; ++j)
            {
                mx = std::max(mx, prev - prefixSum[j - 1] * weight);
                prev = dpTable[j];
                dpTable[j] =
                    std::max(dpTable[j - 1], prefixSum[j] * weight + mx);
            }
        }
        return dpTable[n];
    }
};