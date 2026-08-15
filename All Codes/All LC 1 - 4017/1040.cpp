// Link: https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) for sorting the stones array
    // SC: O(1) for in-place sorting
    // Approach:
    //    1. Sort the stones array.
    //    2. Calculate the maximum number of moves by moving an endpoint stone inward.
    //    3. Calculate the minimum number of moves by using a sliding window approach to find the largest group of consecutive stones and then calculating how many stones are outside that group.
    //    4. Return the minimum and maximum number of moves as a vector.
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        // Moving an endpoint stone inward: the other n-1 stones bound the
        // slots; whichever endpoint we abandon, every empty slot in the
        // remaining span costs one move.
        int maxMoves = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - (n - 2);

        int minMoves = INT_MAX;
        for (int i = 0, j = 0; j < n; j++)
        {
            while (stones[j] - stones[i] + 1 > n)
                i++;
            int cnt = j - i + 1;
            if (cnt == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                // n-1 stones already consecutive, last stone far away:
                // it can't slide next to them in one move (no endpoint rule)
                minMoves = min(minMoves, 2);
            else
                minMoves = min(minMoves, n - cnt);
        }
        return {minMoves, maxMoves};
    }
};
