// Link: https://leetcode.com/problems/count-ways-to-choose-coprime-integers-from-rows/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(maxVal * rows * cols)  SC: O(maxVal)
// Approach: Möbius inclusion-exclusion. For a fixed divisor d, the number of
// selections (one element per row) where d divides every chosen element is
// the product, over rows, of (count of elements in that row divisible by
// d). Summing mu(d) * that product over all d gives the count of selections
// whose overall gcd is exactly 1 (standard Möbius gcd=1 counting identity).
class Solution
{
    static const long long MOD = 1000000007;

public:
    int countCoprime(vector<vector<int>> &mat)
    {
        int maxVal = 0;
        for (auto &row : mat)
            for (int v : row)
                maxVal = max(maxVal, v);

        vector<int> mu(maxVal + 1, 1);
        vector<int> spf(maxVal + 1, 0);
        vector<int> primes;
        for (int i = 2; i <= maxVal; i++)
        {
            if (spf[i] == 0)
            {
                spf[i] = i;
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes)
            {
                if (p > spf[i] || (long long)i * p > maxVal)
                    break;
                spf[i * p] = p;
                mu[i * p] = (p == spf[i]) ? 0 : -mu[i];
            }
        }
        mu[0] = 0;
        if (maxVal >= 1)
            mu[1] = 1;

        long long ans = 0;
        for (int d = 1; d <= maxVal; d++)
        {
            if (mu[d] == 0)
                continue;
            long long product = 1;
            bool ok = true;
            for (auto &row : mat)
            {
                long long cnt = 0;
                for (int v : row)
                    if (v % d == 0)
                        cnt++;
                if (cnt == 0)
                {
                    ok = false;
                    break;
                }
                product = (product * cnt) % MOD;
            }
            if (!ok)
                continue;
            ans = (ans + mu[d] * product) % MOD;
        }
        ans = ((ans % MOD) + MOD) % MOD;
        return (int)ans;
    }
};
