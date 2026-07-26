// Link: https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) – three modular exponentiations each taking O(log n)
// SC: O(1)     – constant extra space
// Approach: Inclusion-Exclusion. A string of length n can be rearranged to
// contain "leet" iff it has ≥1 'l', ≥1 't', and ≥2 'e's.
// Let A=missing 'l', B=missing 't', C=fewer than 2 'e's (0 or 1 'e').
// Answer = 26^n - |A∪B∪C|, expanded via inclusion-exclusion:
//   |A|=25^n, |B|=25^n, |C|=25^n + n·25^(n-1)
//   |A∩B|=24^n, |A∩C|=24^n+n·24^(n-1), |B∩C|=24^n+n·24^(n-1)
//   |A∩B∩C|=23^n+n·23^(n-1)
// Simplifies to:
//   26^n - 25^(n-1)·(n+75) + 24^(n-1)·(2n+72) - 23^(n-1)·(n+23)
class Solution
{
public:
    long long mpow(long long base, long long exp, long long mod)
    {
        long long res = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int stringCount(int n)
    {
        long long mod = 1e9 + 7;
        long long ans = (mpow(26, n, mod) - mpow(25, n - 1, mod) * (75 + n) +
                         mpow(24, n - 1, mod) * (2 * n + 72) -
                         mpow(23, n - 1, mod) * (n + 23)) %
                        mod;

        if (ans < 0)
            ans += mod;
        return ans;
    }
};
