// Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(1)
// Approach: We can use dynamic programming to keep track of the maximum number of fruits that can be collected at each cell in the grid. We can iterate through the grid and for each cell, we can calculate the maximum number of fruits that can be collected by taking the maximum of the three possible previous cells (top-left, top, top-right) and adding the number of fruits in the current cell. We can also keep track of the maximum number of fruits collected so far and return it at the end. We can also optimize the space complexity by using a single array to store the maximum number of fruits collected at each cell in the current row and updating it as we iterate through the grid.
class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        const int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += fruits[i][i];
        for (int i = 0; i < n - 2; i++)
        {
            fruits[i][n - i - 2] = fruits[i][n - i - 3] = 0;
        }
        fruits[n - 2][0] = 0;

        for (int i = 1; i < n; i++)
        {
            int j0 = max(n - 1 - i, i + 1);
            for (int j = j0; j < n - 1; j++)
            {
                fruits[i][j] +=
                    max(fruits[i - 1][j - 1],
                        max(fruits[i - 1][j], fruits[i - 1][j + 1]));
                fruits[j][i] +=
                    max(fruits[j - 1][i - 1],
                        max(fruits[j][i - 1], fruits[j + 1][i - 1]));
            }
            fruits[i][n - 1] += max(fruits[i - 1][n - 1], fruits[i - 1][n - 2]);
            fruits[n - 1][i] += max(fruits[n - 1][i - 1], fruits[n - 2][i - 1]);
        }
        ans += fruits[n - 2][n - 1] + fruits[n - 1][n - 2];
        return ans;
    }
};
