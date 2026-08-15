// Link: https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) where n is the number of robots and walls.
// SC: O(n) for the rds vector and O(1) for other variables
// Approach: The solution uses a greedy approach to maximize the number of walls destroyed by robots. It first sorts the robots based on their positions and the walls in ascending order. Then, it iterates through the robots and calculates the number of walls that can be destroyed by each robot when shooting left and right. It maintains two dynamic programming states (dp0 and dp1) to keep track of the maximum walls destroyed when the previous robot shoots left or right. The final result is the maximum of dp0 and dp1 after processing all robots.
class Solution
{
public:
    static int maxWalls(vector<int> &robots_, vector<int> &distance_,
                        vector<int> &walls)
    {
        struct robot_and_distance
        {
            robot_and_distance() {}

            robot_and_distance(int pos, int shoot_dist)
                : pos(pos), shoot_dist(shoot_dist) {}

            int pos;
            int shoot_dist;
        };

        vector<robot_and_distance> rds;
        rds.reserve(robots_.size());
        for (size_t i = 0; i < robots_.size(); i++)
            rds.push_back(robot_and_distance(robots_[i], distance_[i]));
        std::sort(rds.begin(), rds.end(),
                  [](auto &a, auto &b)
                  { return a.pos < b.pos; });

        std::sort(walls.begin(), walls.end());

        auto wit = walls.begin();
        unsigned dp0 = 0;
        unsigned dp1 = 0;
        vector<int>::iterator wit_after_prev_right_reach;

        for (size_t ri = 0; ri < robots_.size(); ri++)
        {
            // "wit" points to the wall located just after the previous (ri - 1)
            // robot

            unsigned shoot_left_count = 0;
            unsigned shoot_right_count = 0;

            // calculate shoot left
            int shoot_left_reach = rds[ri].pos - rds[ri].shoot_dist;
            if (ri > 0 && shoot_left_reach <= rds[ri - 1].pos)
                shoot_left_reach = rds[ri - 1].pos + 1;
            while (wit < walls.end() && *wit < shoot_left_reach)
                wit++;
            auto wit_before_shoot_left_reach = wit;
            while (wit < walls.end() && *wit < rds[ri].pos)
            {
                shoot_left_count++;
                wit++;
            }
            if (wit < walls.end() && *wit == rds[ri].pos)
                shoot_left_count++;

            // "wit" points to the wall located just after this robot

            // calculate shoot right
            int shoot_right_reach = rds[ri].pos + rds[ri].shoot_dist;
            if (ri < robots_.size() - 1 && shoot_right_reach >= rds[ri + 1].pos)
                shoot_right_reach = rds[ri + 1].pos - 1;
            auto wit_after_right_reach = wit;
            while (wit_after_right_reach < walls.end() &&
                   *wit_after_right_reach <= shoot_right_reach)
            {
                shoot_right_count++;
                wit_after_right_reach++;
            }

            // -------------------------------------

            if (ri == 0)
            {
                dp0 = shoot_left_count;
                dp1 = shoot_right_count;
            }
            else
            {
                // if prev robot shoots left, no overlap
                size_t left_if_prev_shot_left = shoot_left_count;

                // if prev robot shoots right, we may have overlap with the
                // current robot shooting left.
                size_t left_if_prev_shot_right;
                if (wit_after_prev_right_reach <= wit_before_shoot_left_reach)
                {
                    left_if_prev_shot_right = shoot_left_count;
                }
                else
                {
                    // we have walls shot by both previous robot to the right,
                    // and current robot to the left
                    left_if_prev_shot_right = 0;
                    for (auto wit1 = wit_after_prev_right_reach;
                         wit1 < walls.end() && *wit1 <= rds[ri].pos; wit1++)
                        left_if_prev_shot_right++;
                }

                size_t left = std::max(dp0 + left_if_prev_shot_left,
                                       dp1 + left_if_prev_shot_right);
                size_t right = std::max(dp0, dp1) + shoot_right_count;

                dp0 = left;
                dp1 = right;
            }

            wit_after_prev_right_reach = wit_after_right_reach;
        }

        return std::max(dp0, dp1);
    }
};
