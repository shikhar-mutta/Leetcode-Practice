// Link: https://leetcode.com/problems/prime-arrangements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log log n) for Sieve of Eratosthenes + O(n) for counting primes + O(n) for factorials
// SC: O(n) for the prime array
//  Approach:
//   1. Use the Sieve of Eratosthenes to count the number of prime numbers up to n.
//   2. Calculate the number of non-prime numbers as n - prime_count.
//   3. The number of valid arrangements is the factorial of the number of primes multiplied by the factorial of the number of non-primes, modulo 10^9 + 7.
//   4. Return the result.
class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long factorial(int n)
    {
        long long result = 1;
        for (int i = 2; i <= n; i++)
        {
            result = (result * i) % MOD;
        }
        return result;
    }
    int numPrimeArrangements(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }
        int pirmecount = 0;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
                pirmecount++;
        }
        int npc = n - pirmecount;
        return (factorial(pirmecount) * factorial(npc)) % MOD;
    }
};