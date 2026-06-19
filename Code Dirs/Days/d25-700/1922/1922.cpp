// Link: https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
class Solution
{
public:
    ll power(ll x, ll y)
    {
        ll res = 1;
        x = x % mod;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % mod; // mod is used to prevent overflow
            x = (x * x) % mod;
            y = y >> 1;
        }
        return res;
    }
    int countGoodNumbers(ll n)
    {
        ll even = (n + 1) / 2;
        ll odd = n / 2;
        ll ans = (power(5, even) * power(4, odd)) % mod;
        return ans;
    }
};
