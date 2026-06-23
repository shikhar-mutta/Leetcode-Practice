// Link: https://leetcode.com/problems/minimum-bitwise-or-from-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(17 * m * n), SC: O(1)
    int minimumOR(vector<vector<int>> &grid)
    {
        int mask = (1 << 17) - 1;     // bit mask with all 16 bits set
        for (int b = 16; b >= 0; --b) // try to turn off bit b
        {
            int cand = mask & ~(1 << b); // candidate mask with bit b turned off
            bool ok = true;
            for (const auto &row : grid)
            {
                bool rowOk = false; // assume row has no submask of candidate
                for (int x : row)
                    if ((x & ~cand) == 0) // is first bit is off in x, then x is a submask of candidate
                    {
                        rowOk = true;
                        break;
                    }
                if (!rowOk)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                mask = cand; // reduce mask to candidate if feasible
        }
        return mask;
    }
};
