// Link: https://leetcode.com/problems/walking-robot-simulation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto& o : obstacles) obs.insert({o[0], o[1]});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0, x = 0, y = 0;
        long long best = 0;
        for (int cmd : commands) {
            if (cmd == -2) dir = (dir + 3) % 4;
            else if (cmd == -1) dir = (dir + 1) % 4;
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (obs.count({nx, ny})) break;
                    x = nx; y = ny;
                }
            }
            best = max(best, (long long)x*x + (long long)y*y);
        }
        return (int)best;
    }
};
