// Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: each row of 3 cells is either an "ABA" pattern (2 distinct
// colors, 6 arrangements) or "ABC" pattern (3 distinct colors, 6
// arrangements). Known transition counts between consecutive rows:
// ABA->ABA (3 ways), ABA->ABC (2), ABC->ABA (2), ABC->ABC (2). Track
// running totals for each pattern type across n rows, mod 1e9+7.
class Solution
{
public:
    int numOfWays(int n)
    {
        const long long MOD = 1e9 + 7;
        long long aba = 6, abc = 6;
        for (int i = 2; i <= n; i++)
        {
            long long nAba = (aba * 3 + abc * 2) % MOD;
            long long nAbc = (aba * 2 + abc * 2) % MOD;
            aba = nAba;
            abc = nAbc;
        }
        return (int)((aba + abc) % MOD);
    }
};
