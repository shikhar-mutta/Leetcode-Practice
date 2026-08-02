// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(max(tx, ty))) - The while loop continues until the target coordinates are reduced to the starting coordinates.
// SC: O(1) - Constant space is used for variables and no additional data structures are utilized.
// Approach: The solution employs a greedy approach, working backwards from the target coordinates (tx, ty) to the starting coordinates (sx, sy). It checks if the target can be reached by reversing the allowed moves. The algorithm handles three main cases: when the target coordinates are equal, when tx is greater than ty, and when tx is less than ty. It ensures that the target coordinates do not fall below the starting coordinates and counts the number of moves required to reach the start.
class Solution
{
public:
    int minMoves(int sx, int sy, int tx, int ty)
    {
        int moves = 0;

        while (tx > sx || ty > sy)
        {
            // If targets fall below start coordinates, the target is unreachable
            if (tx < sx || ty < sy)
            {
                return -1;
            }

            // Case 1: Target coordinates are equal (tx == ty)
            if (tx == ty)
            {
                if (sx == 0)
                {
                    tx = 0;
                }
                else if (sy == 0)
                {
                    ty = 0;
                }
                else
                {
                    return -1;
                }
                moves++;
                continue;
            }

            // Swap to ensure tx > ty for uniform logic
            if (tx < ty)
            {
                swap(tx, ty);
                swap(sx, sy);
            }

            // Case 2: tx > ty
            moves++;
            if (tx > 2 * ty)
            {
                if (tx % 2 != 0)
                {
                    return -1; // Must be even to reverse a doubling move
                }
                tx /= 2;
            }
            else
            {
                tx -= ty;
            }
        }

        return (tx == sx && ty == sy) ? moves : -1;
    }
};
