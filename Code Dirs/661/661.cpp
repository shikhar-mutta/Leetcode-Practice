// Link: https://leetcode.com/problems/image-smoother/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int rows = img.size(), cols = img[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int sum = 0, cnt = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ni = i + di, nj = j + dj;
                        // Check if the neighboring cell is within bounds
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
                        {
                            sum += img[ni][nj];
                            cnt++;
                        }
                    }
                }
                // Calculate the average and assign it to the answer matrix
                ans[i][j] = sum / cnt;
            }
        }

        return ans;
    }
};
