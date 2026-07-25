// Link: https://leetcode.com/problems/minimum-sideway-jumps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//    Approach:
//      1. We can use a greedy approach to solve this problem.
//      2. We can keep track of the current lane and the number of side jumps
//         we have made so far.
//      3. We can iterate through the obstacles array and check if there is an
//         obstacle in the current lane at the next point.
//      4. If there is no obstacle, we can move to the next point in the same lane.
//      5. If there is an obstacle, we can choose a new lane to jump to. We can choose the lane with the furthest obstacle in the future.
//      6. We can keep track of the number of side jumps we have made and return it at the end.
//    Note: This solution assumes that the input is valid and there is always a path to the end.
class Solution
{
public:
    int minSideJumps(vector<int> &obstacles)
    {
        size_t point = 1;
        int lane = 2;
        int sideJumps = 0;
        while (point < obstacles.size())
        {
            if (obstacles[point] != lane)
            {
                ++point;
            }
            else
            {
                int leftLane;
                int rightLane;
                switch (lane)
                {
                case 1:
                    leftLane = 3;
                    rightLane = 2;
                    break;
                case 2:
                    leftLane = 1;
                    rightLane = 3;
                    break;
                case 3:
                    leftLane = 2;
                    rightLane = 1;
                    break;
                default:
                    // Should never happen.
                    assert(0);
                }

                int curPoint = point - 1;
                assert(curPoint >= 0);
                int curObstacle = obstacles[curPoint];
                if (curObstacle == 0)
                {
                    int nextLeftObstacle = 0;
                    int nextRightObstacle = 0;
                    for (int nextPoint = point + 1;
                         nextPoint < obstacles.size(); ++nextPoint)
                    {
                        int nextObstacle = obstacles[nextPoint];
                        if (nextObstacle == lane)
                        {
                            continue;
                        }
                        if (nextObstacle == leftLane)
                        {
                            nextLeftObstacle = nextPoint;
                            nextRightObstacle = std::numeric_limits<int>::max();
                            break;
                        }
                        if (nextObstacle == rightLane)
                        {
                            nextLeftObstacle = std::numeric_limits<int>::max();
                            nextRightObstacle = nextPoint;
                            break;
                        }
                    }

                    if (nextLeftObstacle < nextRightObstacle)
                    {
                        lane = rightLane;
                    }
                    else if (nextRightObstacle < nextLeftObstacle)
                    {
                        lane = leftLane;
                    }
                    else
                    {
                        ++lane;
                        lane = lane > 3 ? 1 : lane;
                    }
                }
                else
                {
                    if (curObstacle == leftLane)
                    {
                        lane = rightLane;
                    }
                    else
                    {
                        lane = leftLane;
                    }
                }
                ++sideJumps;
            }
        }
        return sideJumps;
    }
};