// Link: https://leetcode.com/problems/super-ugly-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nk), SC: O(n+k)
    //  Approach:
    //   1. Use dynamic programming to find the nth super ugly number.
    //   2. Create a dp array to store the super ugly numbers and initialize the first super ugly number as 1.
    //   3. Create an index array to keep track of the indices of the primes used to generate the next super ugly number.
    //   4. Create a next array to store the next super ugly number for each prime.
    //   5. For each super ugly number, find the minimum value from the next array and update the dp array with that value.
    //   6. Update the index and next arrays for the primes that generated the minimum value.
    //   7. Return the nth super ugly number from the dp array.
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        vector<long long> dp(n);
        dp[0] = 1;
        vector<int> index(k, 0);
        vector<long long> next(k);
        int i;
        int j;
        for (i = 0; i < k; i++)
        {
            next[i] = primes[i];
        }
        for (i = 1; i < n; i++)
        {
            long long mn = next[0];
            for (j = 1; j < k; j++)
            {
                mn = min(mn, next[j]);
            }
            dp[i] = mn;
            for (j = 0; j < k; j++)
            {
                if (next[j] == mn)
                {
                    index[j]++;
                    next[j] = 1LL * primes[j] * dp[index[j]];
                }
            }
        }
        return (int)dp[n - 1];
    }
};