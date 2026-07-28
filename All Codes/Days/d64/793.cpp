// Link: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(k)^2)  SC: O(1)
// Approach: zeroCount(n) (trailing zeros of n!) is non-decreasing and,
// whenever it hits a given k at all, hits it for exactly 5 consecutive
// n's (since every 5th number contributes a factor of 5). Binary search
// for the smallest n with zeroCount(n) >= k; if it doesn't equal k,
// answer is 0, otherwise the answer is always 5.
class Solution
{
    long long zeroCount(long long n)
    {
        long long count = 0;
        for (long long p = 5; p <= n; p *= 5)
            count += n / p;
        return count;
    }

public:
    int preimageSizeFZF(int k)
    {
        long long lo = 0, hi = 5LL * (k + 1);
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (zeroCount(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return (zeroCount(lo) == k) ? 5 : 0;
    }
};
