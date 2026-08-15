// Link: https://leetcode.com/problems/manhattan-distances-of-all-arrangements-of-pieces/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(1)  SC: O(1)
// Approach: The sum of Manhattan distances between all pairs of pieces can be computed separately for the rows and columns. For a grid of size m x n, the sum of distances for rows can be calculated as m^2 * C(n+1, 3) and for columns as n^2 * C(m+1, 3), where C(a, b) is the binomial coefficient "a choose b". The total sum is then the sum of these two values multiplied by the number of ways to choose k pieces from m*n cells, which is C(m*n - 2, k - 2). The final result is taken modulo 1e9 + 7.
using ll = long long;
const int MX = 1'000'00 + 5;
const int mod = 1'000'000'000 + 7;
ll F[MX + 5], INV_F[MX + 5];

ll qpow(ll x, int n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

auto init = []
{
    F[0] = 1;
    for (int i = 1; i <= MX; ++i)
    {
        F[i] = (F[i - 1] * i) % mod;
    }
    INV_F[MX] = qpow(F[MX], mod - 2);
    for (int i = MX; i; --i)
    {
        INV_F[i - 1] = (INV_F[i] * i) % mod;
    }
    return 0;
}();

ll comb(int m, int n)
{
    return n < 0 || n > m ? 0 : F[m] * INV_F[n] % mod * INV_F[m - n] % mod;
}

class Solution
{
public:
    int distanceSum(int m, int n, int k)
    {
        return comb(m * n - 2, k - 2) * (1LL * m * m % mod * comb(n + 1, 3) % mod + 1LL * n * n % mod * comb(m + 1, 3) % mod) % mod;
    }
};
