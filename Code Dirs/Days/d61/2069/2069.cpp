// Link: https://leetcode.com/problems/walking-robot-simulation-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach:
// 1. We can calculate the perimeter of the rectangle by using the formula: perimeter = 2 * (width + height) - 4.
// 2. We can then keep track of the current position of the robot by using a variable cur, which will be initialized to 0.
// 3. We can then implement the step function, which will take in a number num and update the current position of the robot by adding num to cur and taking the modulo with perimeter.
// 4. We can then implement the getPos function, which will return the current position of the robot by calculating the x and y coordinates based on the value of cur.
// 5. We can then implement the getDir function, which will return the current direction of the robot based on the value of cur and the current position of the robot.
class Robot
{
private:
    int w, h;
    int perimeter;
    int cur;
    bool moved;

public:
    Robot(int width, int height)
    {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
        cur = 0;
        moved = false;
    }

    void step(int num)
    {
        moved = true;
        cur = (cur + num) % perimeter;
    }

    vector<int> getPos()
    {
        int p = cur;

        if (p < w)
        {
            return {p, 0};
        }

        p -= w - 1;
        if (p < h)
        {
            return {w - 1, p};
        }

        p -= h - 1;
        if (p < w)
        {
            return {w - 1 - p, h - 1};
        }

        p -= w - 1;
        return {0, h - 1 - p};
    }

    string getDir()
    {
        if (!moved)
            return "East";

        if (cur == 0)
            return "South";

        int p = cur;

        if (p < w)
            return "East";

        p -= (w - 1);
        if (p < h)
            return "North";

        p -= (h - 1);
        if (p < w)
            return "West";

        return "South";
    }
};