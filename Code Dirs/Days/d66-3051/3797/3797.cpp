// Link: https://leetcode.com/problems/count-routes-to-climb-a-rectangular-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * d)  SC: O(n)
// Approach: We can use dynamic programming to solve this problem. We can use a 1D array to store the number of ways to reach each cell in the grid. We can iterate through the grid and for each cell, we can calculate the number of ways to reach it from the previous cells within the distance d. We can return the total number of ways to reach the last row of the grid.
constexpr int mod = 1000000007;
int np1[750], np2[750];

class Solution
{
public:
    int numberOfRoutes(vector<string> &grid, int d)
    {
        int N = size(grid[0]), dd = min(N - 1, (int)sqrt(d * d - 1)), fst = 1;
        for (int u = size(grid) - 1; u >= 0; --u)
        {
            const auto &r = grid[u];
            if (fst)
            {
                fst = 0;
                for (int i = 0; i < N; ++i)
                    np1[i] = r[i] == '.';
            }
            else
            {
                long long s = 0;
                for (int i = -dd; i < N; ++i)
                {
                    if (i + dd < N)
                        s += np2[i + dd];
                    if (i - dd > 0)
                        s -= np2[i - dd - 1];
                    if (i >= 0)
                        np1[i] = r[i] == '.' ? s % mod : 0;
                }
            }
            // cout << "I: "; for (int i = 0; i < N; ++i) cout << np1[i] << " ";
            // cout << endl;

            long long s = 0;
            for (int i = -d; i < N; ++i)
            {
                if (i + d < N)
                    s += np1[i + d];
                if (i - d > 0)
                    s -= np1[i - d - 1];
                if (i >= 0)
                    np2[i] = r[i] == '.' ? s % mod : 0;
            }
            // cout << "O: "; for (int i = 0; i < N; ++i) cout << np2[i] << " ";
            // cout << endl;
        }
        return accumulate(np2, np2 + N, 0ll) % mod;
    }
};
