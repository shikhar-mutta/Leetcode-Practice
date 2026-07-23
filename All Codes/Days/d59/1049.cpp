// Link: https://leetcode.com/problems/last-stone-weight-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * target) where n is the number of stones and target is half of the total weight of stones
    // SC: O(target) for the reachable array
    //  Approach:
    //   1. We can use dynamic programming to find the maximum weight that can be achieved by selecting a subset of stones such that the total weight is less than or equal to half of the total weight of stones.
    //   2. We can then return the difference between the total weight of stones and twice the maximum weight that can be achieved by selecting a subset of stones.
    //   3. We can use a boolean array to keep track of the reachable weights and update it for each stone.
    //   4. Finally, we can iterate through the reachable weights in reverse order to find the maximum weight that can be achieved.
    int lastStoneWeightII(vector<int> &stones)
    {
        int total = 0;
        for (int s : stones)
            total += s;
        int target = total / 2;

        vector<bool> reachable(target + 1, false);
        reachable[0] = true;
        for (int s : stones)
            for (int j = target; j >= s; j--)
                if (reachable[j - s])
                    reachable[j] = true;

        int best = 0;
        for (int j = target; j >= 0; j--)
            if (reachable[j])
            {
                best = j;
                break;
            }

        return total - 2 * best;
    }
};
