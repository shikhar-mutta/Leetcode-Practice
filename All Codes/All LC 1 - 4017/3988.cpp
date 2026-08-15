// Link: https://leetcode.com/problems/create-grid-with-exactly-k-paths-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
//  Approach: The number of paths from (0,0) to (m-1,n-1) is C(m+n-2, m-1). If k > C(m+n-2, m-1), return empty grid. If m==1 or n==1, return a grid of all dots. If k==1, return a grid with the first row and last column as dots. If n>=k, build a grid with the first two rows and the first k columns as dots, and the last row from column k-1 to n-1 as dots. If m>=k, build a grid with the first two columns and the first k rows as dots, and the last column from row k-1 to m-1 as dots. Otherwise, return a grid with the first row as "..#", the second row as "...", and the last row as "#..".
class Solution
{
    long long C(int a, int b)
    {
        long long r = 1;
        for (int i = 0; i < b; i++)
            r = r * (a - i) / (i + 1);
        return r;
    }
    vector<string> buildHoriz(int m, int n, int k)
    {
        vector<string> g(m, string(n, '#'));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < k; j++)
                g[i][j] = '.';
        for (int i = 1; i < m; i++)
            g[i][k - 1] = '.';
        for (int j = k - 1; j < n; j++)
            g[m - 1][j] = '.';
        return g;
    }
    vector<string> buildVert(int m, int n, int k)
    {
        auto t = buildHoriz(n, m, k);
        vector<string> g(m, string(n, '#'));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = t[j][i];
        return g;
    }

public:
    vector<string> createGrid(int m, int n, int k)
    {
        if (k > C(m + n - 2, min(m, n) - 1))
            return {};
        if (m == 1 || n == 1)
            return vector<string>(m, string(n, '.'));
        if (k == 1)
        {
            vector<string> g(m, string(n, '#'));
            for (int j = 0; j < n; j++)
                g[0][j] = '.';
            for (int i = 0; i < m; i++)
                g[i][n - 1] = '.';
            return g;
        }
        if (n >= k)
            return buildHoriz(m, n, k);
        if (m >= k)
            return buildVert(m, n, k);
        return {"..#", "...", "#.."};
    }
};
