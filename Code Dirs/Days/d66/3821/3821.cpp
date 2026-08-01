// Link: https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k^2). SC: O(k^2). DP, combinatorics.
//  Approach: We can use combinatorics to solve this problem. We can use a bitmask to represent the number of 1s in the binary representation of the number. We can use a DP table to store the number of ways to choose k bits from n bits. We can then use this DP table to find the nth smallest integer with k one bits.
using ll = long long;
const int MX = 60;
ll comb[MX + 1][MX + 1];
auto init = []()
{
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= MX; ++i)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
    return 0;
}();
class Solution
{
public:
    int HI = 49;
    long long nthSmallest(long long n, int k)
    {
        ll ans = 0;
        int rest = k;
        int b = HI;
        while (n > 1 && rest)
        {
            ll sum = comb[b][rest];
            if (n > sum)
            {
                n -= sum;
                rest--;
                ans |= 1LL << b;
            }
            --b;
        }
        for (int i = 0; i <= b && rest > 0; ++i, rest--)
        {
            ans |= 1LL << i;
        }
        return ans;
    }
};
