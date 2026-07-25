// Link: https://leetcode.com/problems/equal-row-and-column-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n^2)
//  Approach:
//  1. Create a map to store the frequency of each column in the grid.
//  2. Iterate through each row in the grid and check if it exists in the map.
//  3. If it exists, add the frequency of that column to the answer.
//  4. Return the final answer.
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mp;
        int ans = 0;
        int n = grid.size();
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] = grid[i][j];
            }
            mp[temp]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[j] = grid[i][j];
            }
            ans += mp[temp];
        }
        return ans;
    }
};