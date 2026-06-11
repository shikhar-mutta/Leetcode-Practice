// Link: https://leetcode.com/problems/find-a-peak-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxElemCol(const vector<vector<int>> &mat, int c)
    {
        int n = mat.size(), r = 0;
        for (int i = 1; i < n; i++)
            if (mat[i][c] > mat[r][c])
                r = i;
        return r;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int tmp, r, rt, lt, mid, low = 0, high = m - 1;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            r = maxElemCol(mat, mid);
            tmp = mat[r][mid];
            rt = mid + 1 < m ? mat[r][mid + 1] : INT_MIN;
            lt = mid - 1 >= 0 ? mat[r][mid - 1] : INT_MIN;
            if (tmp > rt && tmp > lt)
                return {r, mid};
            else if (tmp < lt)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
