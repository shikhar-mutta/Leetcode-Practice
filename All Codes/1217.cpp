// Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int evenCount = 0, oddCount = 0;

        for (int pos : position)
        {
            if (pos % 2 == 0)
            {
                evenCount++; // Count chips at even positions
            }
            else
            {
                oddCount++; // Count chips at odd positions
            }
        }

        // The cost is the minimum of the two counts, since we can move all chips to the position with fewer chips
        return min(evenCount, oddCount);
    }
};
