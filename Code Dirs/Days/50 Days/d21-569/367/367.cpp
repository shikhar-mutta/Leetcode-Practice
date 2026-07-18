// Link: https://leetcode.com/problems/valid-perfect-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(num)), SC: O(1)
    bool isPerfectSquare(int num)
    {
        long long lo = 1, hi = num;
        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long sq = mid * mid;
            if (sq == num)
                return true;
            if (sq < num)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};
