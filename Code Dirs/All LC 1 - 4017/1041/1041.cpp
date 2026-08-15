// Link: https://leetcode.com/problems/robot-bounded-in-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (char c : instructions) {
            if (c == 'G') { x += dx[dir]; y += dy[dir]; }
            else if (c == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};
