// Link: https://leetcode.com/problems/arranging-coins/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n)), SC: O(1)
    // Lower bound problem: k(k+1)/2 <= n => k^2 + k - 2n <= 0
    int arrangeCoins(int n)
    {
        long long lo = 0, hi = n, ans = 0;
        while (lo <= hi)
        {
            long long k = lo + (hi - lo) / 2;
            if (k * (k + 1) / 2 <= n)
            {
                ans = k;
                lo = k + 1;
            }
            else
            {
                hi = k - 1;
            }
        }
        return (int)ans;
    }
};
