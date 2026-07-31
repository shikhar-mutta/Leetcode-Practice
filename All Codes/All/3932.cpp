// Link: https://leetcode.com/problems/count-k-th-roots-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((r^(1/k)) * k) SC: O(1)
//  Approach: iterate over all x such that x^k is in [l, r], counting those
//  that are in the range. Stop when x^k exceeds r, and handle the
//  special case of k=1 separately (all integers in [l, r] are valid).
class Solution
{
public:
    int countKthRoots(int l, int r, int k)
    {
        if (k == 1)
            return r - l + 1;
        int count = 0;
        for (long long x = 0;; x++)
        {
            long long y = 1;
            bool overflow = false;
            for (int i = 0; i < k; i++)
            {
                y *= x;
                if (y > r)
                {
                    overflow = true;
                    break;
                }
            }
            if (overflow)
                break;
            if (y >= l && y <= r)
                count++;
            if (x == 0 && k > 0)
                continue; // x=0 gives y=0, still valid to check but loop must advance
        }
        return count;
    }
};