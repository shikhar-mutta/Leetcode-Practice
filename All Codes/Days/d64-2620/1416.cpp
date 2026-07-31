// Link: https://leetcode.com/problems/restore-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log10(k))  SC: O(n)
//  Approach: dp[i] = number of ways to split s[0..i) into valid array
//  elements. For each end position i, look back up to 10 digits (since
//  k <= 10^9 bounds segment length) for a start j where s[j..i) has no
//  leading zero and its numeric value <= k, adding dp[j], all mod 1e9+7.
class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        const int n{static_cast<int>(s.length())};
        static int dp[10];
        *dp = 1;
        for (int i{n - 1}; i >= 0; --i)
        {
            int nxt{0};
            if (s[i] != '0')
            {
                long long num{0LL};
                for (int j{i}; j < n; ++j)
                {
                    num = num * 10 + s[j] - '0';
                    if (num > k)
                        break;
                    nxt = (nxt + dp[j - i]) % 1000000007;
                }
            }
            memmove(dp + 1, dp, sizeof(dp) - sizeof(int));
            *dp = nxt;
        }
        return *dp;
    }
};