// Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) where m is the number of rows and n is the number of columns
// SC: O(n) where n is the number of columns
//  Approach:
//  1. We can iterate through the matrix and for each row, we can calculate the height of the columns by adding the value of the current cell to the value of the cell above it
//  2. We can then use a frequency array to count the number of columns with the same height and calculate the area of the submatrix by multiplying the height with the number of columns with that height
//  3. We can keep track of the maximum area and return it at the end of the iteration

int freq[100000];
class Solution
{
public:
    static int largestSubmatrix(vector<vector<int>> &matrix)
    {
        const int m = matrix.size(), n = matrix[0].size();
        int area = count(matrix[0].begin(), matrix[0].end(), 1);
        if (m == 1)
            return area;
        if (n == 1)
        {
            for (int i = 1; i < m; i++)
            {
                int &x = matrix[i][0];
                x += -x & matrix[i - 1][0];
                area = max(area, x);
            }
            return area;
        }
        int maxH = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int &x = matrix[i][j];
                x += -x & matrix[i - 1][j];
                maxH = max(maxH, x); // find max height for this row
            }
            memset(freq, 0, sizeof(int) * (maxH + 1));
            for (int x : matrix[i])
            {
                freq[x]++;
            }
            int acc = 0;
            for (int x = maxH; acc < n; x--)
            {
                if (freq[x] > 0)
                {
                    acc += freq[x];
                    area = max(area, acc * x);
                }
            }
        }
        return area;
    }
};
