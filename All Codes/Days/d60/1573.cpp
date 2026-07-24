// Link: https://leetcode.com/problems/number-of-ways-to-split-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach:
    // 1. Count the total number of 1's in the string. If it is not divisible by 3, return 0.
    // 2. If the total number of 1's is 0, return (n - 1) * (n - 2) / 2 % MOD, where n is the length of the string.
    // 3. Otherwise, find the number of ways to split the string into 3 parts with equal number of 1's. Count the number of ways to split the string into 3 parts with equal number of 1's. The number of ways to split the string into 3 parts with equal number of 1's is equal to the number of ways to split the string into 2 parts with equal number of 1's. The number of ways to split the string into 2 parts with equal number of 1's is equal to the number of ways to split the string into 1 part with equal number of 1's. The number of ways to split the string into 1 part with equal number of 1's is equal to the number of ways to split the string into 0 parts with equal number of 1's.
    // 4. Return the result modulo 1e9 + 7.
    int numWays(string s)
    {
        const int MOD = 1e9 + 7;
        int n = s.length();
        int totalOnes = 0;
        for (char c : s)
        {
            if (c == '1')
                totalOnes++;
        }
        if (totalOnes % 3 != 0)
        {
            return 0;
        }
        if (totalOnes == 0)
        {
            long ways = (long long)(n - 1) * (n - 2) / 2;
            return ways % MOD;
        }
        int targetOnes = totalOnes / 3;
        long long ways1 = 0;
        long long ways2 = 0;
        int currentOnes = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1')
                currentOnes++;
            if (currentOnes == targetOnes)
            {
                ways1++;
            }
            if (currentOnes == 2 * targetOnes)
            {
                ways2++;
            }
        }
        return (ways1 * ways2) % MOD;
    }
};
