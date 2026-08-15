// Link: https://leetcode.com/problems/smallest-good-base/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n * log n)  SC: O(1)
//  Approach: For a number n, we want to find the smallest base k such that n can be expressed as a sum of powers of k, all with coefficient 1. This means we are looking for the largest m such that n = k^0 + k^1 + ... + k^(m-1) = (k^m - 1) / (k - 1). We can iterate over possible values of m from 60 down to 2 (since 2^60 is greater than 10^18, the maximum value of n). For each m, we can use binary search to find the appropriate base k. If we find a valid k, we return it. If no valid k is found for any m, we return n-1, which corresponds to the base n-1 (represented as "11" in that base).
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long long num = stoll(n);

        // m = number of digits (all 1's) in the target base.
        // Try the largest possible m first, since larger m -> smaller base k.
        for (int m = 60; m >= 2; m--)
        {
            long long k = (long long)pow((double)num, 1.0 / (m - 1));
            if (k < 2)
                continue;

            // Adjust k with binary search / linear correction to be safe against floating point error
            long long lo = 2, hi = k + 1;
            while (lo <= hi)
            {
                long long mid = lo + (hi - lo) / 2;
                // compute sum = mid^0 + mid^1 + ... + mid^(m-1), guard overflow
                long long sum = 1, cur = 1;
                bool overflow = false;
                for (int i = 1; i < m; i++)
                {
                    // check overflow before multiplying
                    if (cur > (num - sum) / mid + 5)
                    {
                        overflow = true;
                        break;
                    }
                    cur *= mid;
                    sum += cur;
                    if (sum > num)
                    {
                        overflow = true;
                        break;
                    }
                }
                if (overflow || sum > num)
                {
                    hi = mid - 1;
                }
                else if (sum < num)
                {
                    lo = mid + 1;
                }
                else
                {
                    return to_string(mid);
                }
            }
        }

        // Fallback: base (n-1), represented as "11"
        return to_string(num - 1);
    }
};