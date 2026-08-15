// Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int cnt = 0, rows = mat.size(), cols = mat[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j])
                {
                    bool val = true;
                    // check for col elements
                    for (int k = 0; k < rows; k++)
                        if (mat[k][j] && k != i)
                        {
                            val = false;
                            break;
                        }
                    if (!val)
                        break;
                    // check for col elements
                    for (int k = 0; k < cols; k++)
                        if (mat[i][k] && k != j)
                        {
                            val = false;
                            break;
                        }
                    if (val)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
