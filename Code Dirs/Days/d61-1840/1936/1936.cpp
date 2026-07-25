// Link: https://leetcode.com/problems/add-minimum-number-of-rungs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of rungs
// SC: O(1)
//  Approach: Greedy
//  1. Iterate through the rungs and calculate the gap between the current rung and the previous rung.
//  2. If the gap is greater than dist, we need to add (gap - 1) / dist rungs to fill the gap. This is because we can add rungs at a distance of dist from the previous rung, and we need to add enough rungs to fill the gap.
//  3. Update the previous rung to the current rung and continue iterating through the rungs.
//  4. Return the total number of rungs added.
class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        long long res = 0;
        int prev = 0;
        for (int r : rungs)
        {
            int gap = r - prev;
            res += (gap - 1) / dist; // ceil(gap/dist) - 1
            prev = r;
        }
        return res;
    }
};
