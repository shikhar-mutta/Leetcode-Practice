// Link: https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log k)ish via memoized DFS  SC: O(log k)
//  Approach: memoized DFS on (position, jumpPower, canGoDown). From
//  position i: going down to i-1 (only if canGoDown and i>0, and it
//  disables further down-moves until another up-move) or going up to
//  i+2^jumpPower (increments jumpPower, re-enables down-move). Bound the
//  search since jumpPower grows and position only needs to reach around
//  k+1 before further up-moves overshoot uselessly; count visits to
//  position==k.
class Solution
{
public:
    int waysToReachStair(int k)
    {
        // for k = 0 1 2 3 4
        int res[5] = {2, 4, 4, 3, 2};
        if (k < 5)
        {
            return res[k];
        }
        // pascals triangle where pt[n][r] = C(n,r)
        int pt[31][31] = {};
        pt[0][0] = 1;

        for (int i = 1; i < 31; i++)
        {
            pt[i][0] = 1;
            pt[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j];
            }
        }
        // find the power of two just greater than k
        int a = 1;
        int count = 0;
        while (k > a)
        {
            a *= 2;
            count++;
        }
        // after reaching a lets say 2^b, we have at max b+1 decrements, so the
        // interval is [2^b - b - 1 , 2^b], that can be reached, if k is below
        // that then return 0;
        if (k < a - count - 1)
        {
            return 0;
        }
        // if it is in range then check how many steps u need to reach k, then
        // just use the table to evaluate total possibilities, which is
        // C(b+1,2^b - k)
        return pt[count + 1][a - k];
    }
};