// Link: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) where m is the number of rows and n is the number of columns
// SC: O(n) where n is the number of columns
//  Approach:
//  1. We can use dynamic programming to calculate the xor value of each cell in the matrix by using the xor value of the cell above it, the cell to the left of it, and the cell diagonally above and to the left of it
//  2. We can then use a frequency array to count the number of occurrences of each xor value and find the kth largest value
class Solution
{
    int dp[1001]{};
    int freq[128]{};

public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        fill(dp, dp + n + 1, 0);
        fill(freq, freq + 128, 0);
        int maxv = 0;
        for (int r = 0; r < m; r++)
        {
            int diag = 0;
            for (int c = 0; c < n; c++)
            {
                int prev = dp[c + 1];
                int v = matrix[r][c] ^ dp[c] ^ prev ^ diag;
                dp[c + 1] = v;
                diag = prev;
                maxv = max(maxv, v);
                freq[v]++;
            }
        }
        int v = maxv;
        for (; freq[v] < k; v--)
            k -= freq[v];
        return v;
    }
};