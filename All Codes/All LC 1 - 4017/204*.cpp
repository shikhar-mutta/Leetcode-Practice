// Link: https://leetcode.com/problems/count-primes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log log n), SC: O(n)
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i]) // If i is prime, mark all multiples of i as non-prime
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
        }

        int count = 0;
        for (bool prime : isPrime)
            if (prime)
                count++;

        return count;
    }
};
