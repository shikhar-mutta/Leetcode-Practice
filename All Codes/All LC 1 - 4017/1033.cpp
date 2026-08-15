// Link: https://leetcode.com/problems/moving-stones-until-consecutive/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) SC: O(1)
    // Approach: Math
    // 1. Sort the positions of the stones to get the leftmost, middle, and rightmost stones.
    // 2. Calculate the gaps between the stones.
    // 3. Determine the minimum moves based on the gaps:
    //    - If both gaps are 1, no moves are needed (minMoves = 0).
    //    - If either gap is 2 or less, only one move is needed (minMoves = 1).
    //    - Otherwise, two moves are needed (minMoves = 2).
    // 4. Calculate the maximum moves as the sum of the gaps minus 2 (maxMoves = (gap1 - 1) + (gap2 - 1)).
    // 5. Return the minimum and maximum moves as a vector.
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        int lo = pos[0], mid = pos[1], hi = pos[2];
        int gap1 = mid - lo, gap2 = hi - mid;

        int minMoves;
        if (gap1 == 1 && gap2 == 1)
            minMoves = 0;
        else if (gap1 <= 2 || gap2 <= 2)
            minMoves = 1;
        else
            minMoves = 2;

        int maxMoves = (gap1 - 1) + (gap2 - 1);
        return {minMoves, maxMoves};
    }
};