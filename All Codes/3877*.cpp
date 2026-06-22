// Link: https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * 2^m). SC: O(2^m).
    // DP approach to find the minimum number of removals required to achieve the target XOR value.
    int minRemovals(vector<int> &nums, int target)
    {
        int sumxor = 0;  // XOR of all elements in the array
        int mx = target; // Maximum value between target and elements in the array
        for (auto &num : nums)
        {
            sumxor = sumxor ^ num;
            mx = max(mx, num);
        }

        int t = target ^ sumxor; // The XOR value we need to achieve by removing elements

        int bits = 0;
        while ((1 << bits) <= mx) // Cal num of bits required to represent the maximum value
            bits++;

        int MAXX = 1 << bits; // Maximum possible XOR value based on the number of bits
        vector<int> dp(MAXX, 1e9);
        dp[0] = 0;             // Base case: 0 removals needed to achieve XOR value of 0
        for (auto &num : nums) // Update the dp array for each number in the input array
        {
            for (int x = MAXX - 1; x >= 0; x--)
                if (dp[x] != 1e9)
                { // If the current XOR value x can be achieved with dp[x] removals,
                    // then we can achieve x ^ num by removing one more element (num).
                    dp[x ^ num] = min(dp[x ^ num], dp[x] + 1);
                }
        }

        return dp[t] == 1e9 ? -1 : dp[t];
    }
};
