// Link: https://leetcode.com/problems/row-with-maximum-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ans(2, 0);
        int n = mat.size(), m = mat[0].size(), count;
        for (int i = 0; i < n; i++)
        {
            count = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    count++;
                if (count + (m - j - 1) <= ans[1]) // Early stopping
                    break;
            }
            if (count > ans[1])
            {
                ans[0] = i;
                ans[1] = count;
            }
        }
        return ans;
    }
};
