// Link: https://leetcode.com/problems/robot-collisions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of robots, SC: O(n) where n is the number of robots
//  Approach: We can use a stack to simulate the collisions between robots. We will first sort the robots based on their positions. Then, we will iterate through the sorted robots and for each robot, we will check if it is moving to the right or left. If it is moving to the right, we will push its index onto the stack. If it is moving to the left, we will check if there are any robots in the stack that are moving to the right. If there are, we will simulate the collision between the two robots and update their healths accordingly. If the robot moving to the left has more health than the robot moving to the right, we will pop the robot moving to the right from the stack and decrement its health. If the robot moving to the left has less health than the robot moving to the right, we will decrement its health and continue checking for collisions. If the robot moving to the left has equal health to the robot moving to the right, we will decrement both their healths and pop the robot moving to the right from the stack. Finally, we will return the healths of the robots that survived the collisions.
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<pair<int, int>> actual_idx;

        for (int i = 0; i < positions.size(); ++i)
        {
            actual_idx.push_back({positions[i], i});
        }
        sort(actual_idx.begin(), actual_idx.end());

        stack<int> st;
        for (int i = 0; i < actual_idx.size(); ++i)
        {

            if (directions[actual_idx[i].second] == 'R')
                st.push(actual_idx[i].second);
            else
            {
                while (!st.empty() && healths[actual_idx[i].second] > 0)
                {

                    int top_idx = st.top();
                    st.pop();

                    if (healths[top_idx] > healths[actual_idx[i].second])
                    {
                        healths[top_idx]--;
                        healths[actual_idx[i].second] = 0;
                        st.push(top_idx);
                    }
                    else if (healths[top_idx] <
                             healths[actual_idx[i].second])
                    {
                        healths[top_idx] = 0;
                        healths[actual_idx[i].second]--;
                    }
                    else
                    {
                        healths[top_idx] = 0;
                        healths[actual_idx[i].second] = 0;
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }

        return ans;
    }
};