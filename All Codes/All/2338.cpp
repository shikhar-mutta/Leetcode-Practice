// Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxValue * log(maxValue) + maxValue * log(n))  SC: O(maxValue)
// Approach: For each number i in [1, maxValue], we can factor it into prime factors. For each prime factor p with exponent e, we can distribute the e copies of p into n slots (the length of the array) using the "stars and bars" combinatorial method. The number of ways to do this is C(n - 1 + e, n - 1). We multiply these counts for all prime factors of i to get the total number of ideal arrays starting with i. Finally, we sum this count for all i in [1, maxValue].
using ll = long long;
const int mod = 1'000'000'000 + 7;
const int MX = 2'00'00;

ll F[MX + 1];
ll INV_F[MX + 1];

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

const int MAXN = 2'00'00;
int spf[MAXN + 1];

auto init2 = []()
{
    for (int i = 1; i <= MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    return 0;
}();

// 從 m 個數中選 n 個數的方案數
ll comb(int m, int n)
{
    return n < 0 || n > m ? 0 : F[m] * INV_F[n] % mod * INV_F[m - n] % mod;
}
class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        ll ans = 0;
        for (int i = 1; i <= maxValue; ++i)
        {
            ll res = 1;
            int x = i;
            while (x > 1)
            {
                int p = spf[x];
                int e = 0;
                while (x % p == 0)
                {
                    x /= p;
                    e++;
                }
                res = (res * comb(n - 1 + e, n - 1)) % mod;
            }
            ans = (ans + res) % mod;
        }
        return ans;
    }
};
