// Link: https://leetcode.com/problems/split-array-by-prime-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log log n) SC: O(n)
// Approach: sieve primality up to n-1, sum elements at prime indices
// separately from elements at non-prime indices, return the absolute
// difference.
class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> isPrime(n, true);
        if (n > 0)
            isPrime[0] = false;
        if (n > 1)
            isPrime[1] = false;
        for (int i = 2; (long long)i * i < n; i++)
            if (isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;

        long long primeSum = 0, otherSum = 0;
        for (int i = 0; i < n; i++)
            (isPrime[i] ? primeSum : otherSum) += nums[i];
        return abs(primeSum - otherSum);
    }
};
