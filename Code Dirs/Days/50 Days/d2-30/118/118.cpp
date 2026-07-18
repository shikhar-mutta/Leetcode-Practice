// Link: https://leetcode.com/problems/pascal-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// The Nth row of Pascal's Triangle contains these values:
// C(N-1, 0),  C(N-1, 1),  C(N-1, 2),  ...  C(N-1, N-1)

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> Tri;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = Tri[i - 1][j] + Tri[i - 1][j - 1];
            }
            Tri.push_back(row);
        }
        return Tri;
    }
};