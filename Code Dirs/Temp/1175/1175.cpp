// Link: https://leetcode.com/problems/prime-arrangements/description/

#include <bits/stdc++.h>
using namespace std;

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