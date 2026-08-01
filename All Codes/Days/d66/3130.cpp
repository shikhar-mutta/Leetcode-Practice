// Link: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: Use combinatorics to count the number of ways to split the 1s and 0s into groups of size at most limit. Use inclusion-exclusion principle to count the number of ways to split the 1s into groups of size at most limit. Then, for each possible number of groups of 1s, count the number of ways to split the 0s into groups of size at most limit. Finally, multiply the two counts together and sum over all possible numbers of groups of 1s.
class Solution
{
public:
    static const int MOD = 1000000007;
    static const int MAXN = 1000;
    vector<long long> fact, invFact;
    long long modPow(long long a, long long b)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    void init()
    {
        fact.assign(MAXN + 1, 1);
        invFact.assign(MAXN + 1, 1);
        for (int i = 1; i <= MAXN; i++)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[MAXN] = modPow(fact[MAXN], MOD - 2);
        for (int i = MAXN; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;
    }
    long long nCr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
    long long splitWays(int n, int k, int limit)
    {
        if (k == 0)
            return n == 0;
        long long ans = 0;
        int sign = 1;
        int remaining = n;
        for (int j = 0; j <= k && remaining >= k; j++)
        {
            long long ways = nCr(k, j) * nCr(remaining - 1, k - 1) % MOD;
            if (sign == 1)
                ans = (ans + ways) % MOD;
            else
                ans = (ans - ways + MOD) % MOD;
            sign *= -1;
            remaining -= limit;
        }
        return ans;
    }
    int numberOfStableArrays(int zero, int one, int limit)
    {
        init();
        int start = (min(zero, one) + limit - 1) / limit;
        long long prev = 0;
        long long curr = splitWays(one, start, limit);
        long long next = splitWays(one, start + 1, limit);
        long long ans = 0;
        for (int k = start; k <= zero; k++)
        {
            long long ways = (prev + 2 * curr + next) % MOD;
            ways = ways * splitWays(zero, k, limit) % MOD;
            ans = (ans + ways) % MOD;
            prev = curr;
            curr = next;
            next = splitWays(one, k + 2, limit);
        }
        return ans;
    }
};
