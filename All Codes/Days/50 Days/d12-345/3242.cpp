// Link: https://leetcode.com/problems/design-neighbor-sum-service/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
class NeighborSum
{
public:
    vector<vector<int>> v;
    NeighborSum(vector<vector<int>> &grid)
    {
        this->v = grid;
    }

    int adjacentSum(int value)
    {
        int sum = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int r = -1, c = -1;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[i][j] == value)
                {
                    r = i, c = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int j = dx[i], k = dy[i];
            if (r + j >= 0 && r + j < v.size() && k + c >= 0 && k + c < v.size())
            {
                sum += v[r + j][c + k];
            }
        }
        return sum;
    }

    int diagonalSum(int value)
    {
        int sum = 0;

        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, 1, -1};

        int r = -1, c = -1;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[i][j] == value)
                {
                    r = i, c = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int j = dx[i], k = dy[i];
            if (r + j >= 0 && r + j < v.size() && c + k >= 0 && c + k < v.size())
            {
                sum += v[r + j][c + k];
            }
        }

        return sum;
    }
};
