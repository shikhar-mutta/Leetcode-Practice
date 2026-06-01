// Link: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<int> row(m, 0), col(n, 0);
        for (auto &v : indices) //   v[0] is the row index and v[1] is the column index
        {
            row[v[0]]++;
            col[v[1]]++;
        }
        int ans = 0; //   If the sum of the row and column increments is odd, then the cell will have an odd value
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((row[i] + col[j]) % 2 == 1) // Check if the sum of the row and column increments is odd
                    ans++;
            }
        }
        return ans;
    }
};
