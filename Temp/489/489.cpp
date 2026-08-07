// Link: https://leetcode.com/problems/robot-room-cleaner/description/

#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    virtual bool move() = 0;
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void clean() = 0;
    virtual ~Robot() {}
};

// TC: O(cells)  SC: O(cells)
// Approach: DFS backtracking spiral - clean current cell, try all 4
// directions from current heading, move/recurse/backtrack (move back +
// restore heading) for each unvisited direction
class Solution {
    unordered_set<long long> visited;

    long long encode(int r, int c) {
        return (long long)r * 100000 + c;
    }

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void dfs(Robot& robot, int r, int c, int d) {
        visited.insert(encode(r, c));
        robot.clean();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nd = (d + i) % 4;
            int nr = r + dr[nd], nc = c + dc[nd];
            if (!visited.count(encode(nr, nc)) && robot.move()) {
                dfs(robot, nr, nc, nd);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

public:
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
