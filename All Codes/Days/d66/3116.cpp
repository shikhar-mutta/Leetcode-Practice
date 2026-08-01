// Link: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^m * log(m) * log(answer))  SC: O(2^m)
// Approach: binary search on amount X; count(X) = number of values <= X
// reachable as a multiple of at least one coin, via inclusion-exclusion
// over all 2^m subsets of coins using their LCM. Smallest X with
// count(X) >= k is the answer.
class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        int m = coins.size();
        vector<long long> lcmSubset(1 << m, 0);
        for (int mask = 1; mask < (1 << m); mask++)
        {
            int lowBit = mask & (-mask);
            int idx = __builtin_ctz(lowBit);
            long long prevLcm = lcmSubset[mask ^ lowBit];
            if (prevLcm == 0)
                lcmSubset[mask] = coins[idx];
            else
                lcmSubset[mask] = prevLcm / gcd(prevLcm, (long long)coins[idx]) * coins[idx];
        }
        auto countLE = [&](long long X)
        {
            long long total = 0;
            for (int mask = 1; mask < (1 << m); mask++)
            {
                long long l = lcmSubset[mask];
                if (l > X)
                    continue;
                long long cnt = X / l;
                int bits = __builtin_popcount(mask);
                if (bits % 2 == 1)
                    total += cnt;
                else
                    total -= cnt;
            }
            return total;
        };
        long long lo = 1, hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
