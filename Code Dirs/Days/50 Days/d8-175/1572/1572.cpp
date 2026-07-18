// Link: https://leetcode.com/problems/matrix-diagonal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i];         // Add primary diagonal element
            sum += mat[i][n - 1 - i]; // Add secondary diagonal element
        }
        // If n is odd, subtract the middle element which was added twice
        if (n % 2 == 1)
        {
            sum -= mat[n / 2][n / 2];
        }
        return sum;
    }
};
