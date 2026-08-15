// Link: https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k) SC: O(1)
//  Approach: The problem can be solved using combinatorial mathematics. The number of ways to assign directions to n people such that exactly k people are visible can be calculated using the formula:
//  total ways = n-1Ck * 2
//  where n-1Ck is the number of ways to choose k people from n-1 people (excluding the first person) and 2 is the number of ways to assign directions to the first person (either left or right). The final answer is obtained by taking the result modulo 10^9 + 7 to handle large numbers.

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution
{
public:
    ll power(ll base, ll exp)
    {
        ll res = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    ll modInverse(ll n) { return power(n, MOD - 2); }
    ll nCr(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;
        if (k > n / 2)
            k = n - k;

        ll num = 1, den = 1;
        for (int i = 0; i < k; i++)
        {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modInverse(den)) % MOD;
    }
    int countVisiblePeople(int n, int pos, int k)
    {
        // total ways = n-1Ck
        return (nCr(n - 1, k) * 2) % MOD;
    }
};