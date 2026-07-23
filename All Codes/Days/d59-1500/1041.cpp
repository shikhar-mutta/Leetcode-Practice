// Link: https://leetcode.com/problems/robot-bounded-in-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the instructions string
    // SC: O(1) for the direction and position variables
    //   Approach:
    //    1. We can use a direction array to represent the four possible directions the robot can face (north, east, south, west).
    //    2. We can iterate through the instructions string and update the robot's position and direction based on the current instruction.
    //    3. If the robot returns to the origin (0, 0) or if it is not facing north after executing all the instructions, then it is bounded in a circle.
    //   4. Finally, we can return true if the robot is bounded in a circle, otherwise false.
    bool isRobotBounded(string instructions)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0, x = 0, y = 0;

        for (char c : instructions)
        {
            if (c == 'G')
            {
                x += dx[dir];
                y += dy[dir];
            }
            else if (c == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }

        return (x == 0 && y == 0) || dir != 0;
    }
};
