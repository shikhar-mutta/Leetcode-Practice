// Link: https://leetcode.com/problems/escape-the-ghosts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of ghosts.
    // SC: O(1), as we are using a constant amount of space.
    // Approach:
    //  1. We calculate the Manhattan distance from the origin (0, 0) to the target position (target[0], target[1]) for the player.
    //  2. We iterate through each ghost's position and calculate the Manhattan distance from the ghost's position to the target position.
    //  3. If any ghost's distance to the target is less than or equal to the player's distance, it means the ghost can reach the target before or at the same time as the player, and we return false.
    //  4. If all ghosts have a greater distance to the target than the player, it means the player can reach the target before any ghost, and we return true.
    //  5. The function returns true if the player can escape the ghosts and reach the target, and false otherwise.
    //   Note: The Manhattan distance is calculated as the sum of the absolute differences of the x and y coordinates.
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int myDist = abs(target[0]) + abs(target[1]);
        for (auto &g : ghosts)
        {
            int gDist = abs(g[0] - target[0]) + abs(g[1] - target[1]);
            if (gDist <= myDist)
                return false;
        }
        return true;
    }
};
