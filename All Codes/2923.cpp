// Link: https://leetcode.com/problems/find-champion-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    int findChampion(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            bool isChampion = true;
            for (int j = 0; j < n; j++)
                if (i != j && grid[i][j] <= grid[j][i])
                { // if j has higher or equal score than i, then i cannot be champion
                    isChampion = false;
                    break;
                }
            if (isChampion)
                return i;
        }
        return -1;
    }
};
