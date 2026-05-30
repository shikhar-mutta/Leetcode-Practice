// Link: https://leetcode.com/problems/matrix-cells-in-distance-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> ans; //(0, vector<int>(2));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans.push_back({i, j}); // ans.push_back({i, j});
            }
        }
        // Sort the ans vector based on the distance from (rCenter, cCenter)
        sort(ans.begin(), ans.end(), [&](vector<int> &a, vector<int> &b) // lambda function
             {
            int d1 = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int d2 = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return d1 < d2; });
        // Return the sorted ans vector
        return ans;
    }
};
