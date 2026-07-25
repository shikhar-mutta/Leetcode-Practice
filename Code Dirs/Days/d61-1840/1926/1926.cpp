// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
// Approach:
//   1. We can use BFS to find the nearest exit from the entrance in the maze. We can start from the entrance and explore all the possible paths in the maze. We can use a queue to keep track of the current position and the number of steps taken to reach that position. We can also use a set to keep track of the visited positions to avoid cycles. If we reach an exit, we can return the number of steps taken to reach that exit. If we exhaust all the possible paths and do not find an exit, we can return -1.
class Solution
{
public:
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> qu;
        qu.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';
        int cnt = 0;
        while (!qu.empty())
        {
            int sz = qu.size();
            while (sz--)
            {
                auto temp = qu.front();
                qu.pop();
                int i = temp.first;
                int j = temp.second;
                if (!(i == entrance[0] && j == entrance[1]) &&
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1))
                {
                    return cnt;
                }
                for (auto &dir : direction)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                        maze[new_i][new_j] == '.')
                    {
                        qu.push({new_i, new_j});
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};