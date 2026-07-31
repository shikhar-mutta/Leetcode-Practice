// Link: https://leetcode.com/problems/count-the-number-of-infection-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n + m)
// Approach: We can use a combinatorial approach to count the number of infection sequences. We first precompute the factorials and their modular inverses up to n using Fermat's Little Theorem. Then, we iterate through the sick array to calculate the lengths of healthy segments between sick individuals. For each segment, we calculate the number of ways to arrange the healthy individuals using the formula for combinations, taking into account that the middle segments can have two arrangements (left or right). Finally, we multiply the results for all segments and return the total count modulo 1e9 + 7.
const int mod = 1e9 + 7;
using ll = long long;
bool ok = false;
int N = 100005;
vector<int> f(N);

class Solution
{
public:
    void fun()
    {
        if (ok)
        {
            return;
        }
        ok = true;
        f[0] = 1;
        for (int i = 1; i <= 100000; i++)
        {
            // f[i]=(i*f[i-1]*1LL)%mod; RUN TIME ERROR
            // First, i * f[i-1] is evaluated. can cause RUN TIME ERROR
            f[i] = (1LL * i * f[i - 1]) % mod;
        }
        return;
    }
    ll pw(ll a, ll b)
    {
        ll res = 1;
        a = (a % mod);
        while (b)
        {
            if (b & 1)
            {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res % mod;
    }
    int numberOfSequence(int n, vector<int> &sick)
    {
        fun();
        int m = sick.size();

        ll s = 0;
        ll len = 0;
        ll k = 0; // ONLY MIDDLE SEGMENTS
        ll den = 1LL;

        len = sick[0] - 0;
        if (len > 0)
        {
            s += len;
            ll curf = (f[len]) % mod;
            den = (den * 1LL * curf) % mod;
        }

        for (int j = 1; j < m; j++)
        {
            len = sick[j] - sick[j - 1] - 1;
            if (len > 0)
            {
                s += len;
                k += (len - 1);
                ll curf = (f[len]) % mod;
                den = (den * 1LL * curf) % mod;
            }
        }

        len = n - sick[m - 1] - 1;
        if (len > 0)
        {
            s += len;
            ll curf = (f[len]) % mod;
            den = (den * 1LL * curf) % mod;
        }

        ll num = f[s] % mod;
        ll pd = (pw(2, k)) % mod;
        ll invd = pw(den, mod - 2) % mod;
        ll ans = num;
        ans = (ans * invd) % mod;
        ans = (ans * pd) % mod;
        return ans;
    }
};
