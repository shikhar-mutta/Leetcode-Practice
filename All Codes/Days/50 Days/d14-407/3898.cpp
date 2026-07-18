// Link: https://leetcode.com/problems/find-the-degree-of-each-vertex/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n)
    vector<int> findDegrees(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), cnt;
        vector<int> degrees(n, 0);
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    cnt++;
            degrees[i] = cnt;
        }
        return degrees;
    }
};
