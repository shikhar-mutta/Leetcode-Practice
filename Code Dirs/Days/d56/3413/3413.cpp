// Link: https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) + O(n) = O(nlogn)
    // SC: O(1)
    // Approach:
    // 1. Sort the coins based on the starting position of each bag.
    // 2. Use two pointers to find the maximum coins that can be collected from k consecutive bags.
    // 3. For each bag, calculate the total coins that can be collected from the bags that are completely within the k-length segment and the partial coins from the bag that is partially within the segment.
    // 4. Return the maximum coins that can be collected from k consecutive bags.
    long long maximumCoins(vector<vector<int>> &coins, int k)
    {
        sort(coins.begin(), coins.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int n = coins.size();
        long long result = 0;
        long long currentSum = 0;

        // Case 1: k-length segment starts at coins[i][0]
        for (int i = 0, j = 0; i < n; i++)
        {
            long long windowEnd = (long long)coins[i][0] + k - 1;

            while (j < n && coins[j][1] <= windowEnd)
            {
                currentSum += (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            if (j < n)
            {
                long long overlapLength = max(0LL, windowEnd - coins[j][0] + 1);
                long long partial = overlapLength * coins[j][2];

                result = max(result, currentSum + partial);
            }

            currentSum -= (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        // Case 2: k-length segment ends at coins[i][1]
        currentSum = 0;

        for (int i = 0, j = 0; i < n; i++)
        {
            currentSum += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];

            long long windowStart = (long long)coins[i][1] - k + 1;

            while (coins[j][1] < windowStart)
            {
                currentSum -= (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            long long extraLength = max(0LL, windowStart - coins[j][0]);
            long long partial = extraLength * coins[j][2];

            result = max(result, currentSum - partial);
        }

        return result;
    }
};
