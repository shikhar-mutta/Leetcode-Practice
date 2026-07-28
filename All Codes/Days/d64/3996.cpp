// Link: https://leetcode.com/problems/even-number-of-knight-moves/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1)  SC: O(1)  (board is fixed 8x8)
// Approach: BFS over the doubled state space (x, y, moveParity) on the
// 8x8 board and check whether the state (target, parity=0) is reachable
// from (start, parity=0) — directly answers "reachable in an even number
// of moves" without assuming minimum-distance parity always suffices.
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx[8] = {1,1,-1,-1,2,2,-2,-2};
        int dy[8] = {2,-2,2,-2,1,-1,1,-1};
        bool visited[8][8][2] = {};
        queue<tuple<int,int,int>> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]][0] = true;
        while (!q.empty()) {
            auto [x, y, p] = q.front(); q.pop();
            if (x == target[0] && y == target[1] && p == 0) return true;
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d], ny = y + dy[d], np = p ^ 1;
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
                if (visited[nx][ny][np]) continue;
                visited[nx][ny][np] = true;
                q.push({nx, ny, np});
            }
        }
        return false;
    }
};
