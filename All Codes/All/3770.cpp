// Link: https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log log n)  SC: O(n)
//  Approach: sieve of Eratosthenes to find all primes up to MX, then
//  compute prefix sums and check which are prime.
//  Note: MX is set to 500000 because the largest prime sum of consecutive primes that is itself prime is 498091, which is less than 500000.
class Solution
{
    static constexpr int MX = 500000;
    static vector<bool> isPrime;
    static vector<int> primes;
    static vector<int> good;
    static bool initialized;

    static void init()
    {
        if (initialized)
            return;
        initialized = true;

        isPrime.assign(MX + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= MX; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
                if (1LL * i * i <= MX)
                {
                    for (int j = i * i; j <= MX; j += i)
                        isPrime[j] = false;
                }
            }
        }

        good.push_back(0);
        int sum = 0;
        for (int p : primes)
        {
            sum += p;
            if (sum > MX)
                break;
            if (isPrime[sum])
                good.push_back(sum);
        }
    }

public:
    int largestPrime(int n)
    {
        init();
        auto it = upper_bound(good.begin(), good.end(), n);
        return *(--it);
    }
};

vector<bool> Solution::isPrime;
vector<int> Solution::primes;
vector<int> Solution::good;
bool Solution::initialized = false;