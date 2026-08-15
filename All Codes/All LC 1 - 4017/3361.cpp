// Link: https://leetcode.com/problems/shift-distance-between-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: use prefix sums to quickly calculate the cost of shifting between any two positions.
// The cost of shifting from character x to character y can be calculated in two ways:
// 1. Forward shift: sum of nextCost from x to y (wrapping around if necessary).
// 2. Backward shift: sum of previousCost from y to x (wrapping around if necessary).
// The minimum of these two costs is added to the total shift distance.
class Solution
{
public:
    long long shiftDistance(string s, string t, vector<int> &nextCost,
                            vector<int> &previousCost)
    {
        const int M = 26;
        vector<long long> preNext(2 * M + 1, 0), prePrev(2 * M + 1, 0);
        for (int i = 0; i < 2 * M; i++)
        {
            preNext[i + 1] = preNext[i] + nextCost[i % M];
            prePrev[i + 1] = prePrev[i] + previousCost[(i + 1) % M];
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            long long forward = preNext[y + (y < x ? M : 0)] - preNext[x];
            long long backward = prePrev[x + (x < y ? M : 0)] - prePrev[y];
            ans += min(forward, backward);
        }

        return ans;
    }
};