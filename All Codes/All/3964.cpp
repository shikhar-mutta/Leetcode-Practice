// Link: https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: mark positions already illuminated by existing bulbs using
//  a difference array. Then greedily scan left to right: at the first
//  uncovered position, place a new radius-1 bulb as far right as
//  possible (at i+1, covering i..i+2) and jump past its coverage.
class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        int n(lights.size()), pre[n + 1], res(0);
        memset(pre, 0, sizeof(pre));
        for (int i(0); i < n; ++i)
            if (lights[i])
            {
                ++pre[max(0, i - lights[i])];
                --pre[min(n, i + lights[i] + 1)];
            }
        int k(0);
        for (int i(0), s(0); i < n; ++i)
        {
            k += !(s += pre[i]);
            if (k && s)
            {
                res += (k + 2) / 3;
                k = 0;
            }
        }

        return res += (k + 2) / 3;
    }
};