// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (const auto &row : grid)
        {
            for (int num : row)
            {
                if (num < 0)
                    count++;
            }
        }
        return count;
    }
};
