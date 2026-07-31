// Link: https://leetcode.com/problems/smallest-all-ones-multiple/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k) SC: O(1)
//  Approach: build the repunit's remainder mod k digit by digit
//  (rem = rem*10+1 mod k). By pigeonhole the remainder must repeat within
//  k steps if it never hits 0, so cap the search at k iterations.
class Solution
{
public:
    int minAllOneMultiple(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int rem = 0;
        for (int len = 1; len <= k; len++)
        {
            rem = (rem * 10 + 1) % k;
            if (rem == 0)
                return len;
        }
        return -1;
    }
};