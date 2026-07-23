// Link: https://leetcode.com/problems/walking-robot-simulation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) SC: O(m)
    //  Approach:
    //  1. We use a set to store the obstacles for quick lookup.
    //  2. We define the possible directions the robot can face (north, east, south, west) using two arrays dx and dy.
    //  3. We initialize the robot's starting position at (0, 0) and its initial direction facing north.
    //  4. We iterate through the commands and update the robot's direction or position based on the command.
    //  5. If the command is -1, we turn the robot 90 degrees to the right (clockwise). If the command is -2, we turn the robot 90 degrees to the left (counter-clockwise).
    //  6. If the command is a positive integer, we move the robot forward in the current direction for the specified number of steps, checking for obstacles at each step. If an obstacle is encountered, we stop moving in that direction.
    //  7. We keep track of the maximum distance squared from the origin that the robot reaches during its movement.
    //  8. Finally, we return the maximum distance squared as the result.
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> obs;
        for (auto &o : obstacles)
            obs.insert({o[0], o[1]});

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0, x = 0, y = 0;
        int best = 0;

        for (int cmd : commands)
        {
            if (cmd == -1)
                dir = (dir + 1) % 4;
            else if (cmd == -2)
                dir = (dir + 3) % 4;
            else
            {
                for (int i = 0; i < cmd; i++)
                {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (obs.count({nx, ny}))
                        break;
                    x = nx;
                    y = ny;
                    best = max(best, x * x + y * y);
                }
            }
        }
        return best;
    }
};
