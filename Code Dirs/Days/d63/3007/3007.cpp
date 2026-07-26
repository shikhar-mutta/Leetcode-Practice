// Link: https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(maxNum) * 60/x) for the binary search over check()
// SC: O(1)
// Approach: binary search on the answer n. check(k,x,n) sums, for every bit
// position that's a multiple of x, how many numbers in [1,n] have that bit
// set (via the periodic set-bit-count formula: full periods contribute
// half the period each, plus a partial remainder), bailing early once the
// running sum exceeds k. Largest n with sum <= k is the answer.
class Solution
{
public:
    int solve(int num, int x)
    {
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((i + 1) % x == 0)
            {
                if ((num & (1 << i)) != 0)
                    cnt++;
            }
        }
        return cnt;
    }
    bool check(long long k, int x, long long n)
    {
        long long sum = 0;

        for (int bit = x - 1; bit < 60; bit += x)
        {

            long long block = 1LL << (bit + 1);

            long long full = (n + 1) / block;
            long long rem = (n + 1) % block;

            sum += full * (1LL << bit);
            sum += max(0LL, rem - (1LL << bit));

            if (sum > k)
                return false;
        }

        return true;
    }
    long long findMaximumNumber(long long k, int x)
    {
        long long l = 0;
        long long h = 1e15;
        long long ans = 0;
        while (l <= h)
        {
            long long mid = l + (h - l) / 2;
            if (check(k, x, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};