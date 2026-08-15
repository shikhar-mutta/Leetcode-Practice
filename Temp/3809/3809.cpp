// Link: https://leetcode.com/problems/best-reachable-tower/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: filter towers within radius using Manhattan distance
//  comparison, then pick the tower with highest quality, breaking ties
//  by lexicographically smallest (x, y).
class Solution
{
public:
    vector<int> bestTower(const vector<vector<int>> &towers,
                          const vector<int> &center, int radius)
    {
        vector<int> bestTower = {-1, -1, -1};

        for (const vector<int> &tower : towers)
        {
            if ((abs(tower[0] - center[0]) + abs(tower[1] - center[1])) <=
                radius)
            {
                if ((tower[2] > bestTower[2]) ||
                    ((tower[2] == bestTower[2]) && (tower < bestTower)))
                {
                    bestTower = tower;
                }
            }
        }

        return {bestTower[0], bestTower[1]};
    }
};