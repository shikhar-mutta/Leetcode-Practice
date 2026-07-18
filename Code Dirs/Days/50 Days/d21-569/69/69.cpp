// Link: https://leetcode.com/problems/sqrtx/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(x)), SC: O(1)
    int mySqrt(int x)
    {
        long long lo = 0, hi = x, ans = 0;
        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (mid * mid <= x)
                ans = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        return (int)ans;
    }
};
