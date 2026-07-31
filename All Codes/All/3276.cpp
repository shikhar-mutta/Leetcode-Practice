// Link: https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) where n is the length of the grid
// SC: O(n^2) where n is the length of the grid
// Approach: We can use the Hungarian algorithm to solve this problem. We can create a cost matrix where the rows represent the cells in the grid and the columns represent the values in the grid. We can then use the Hungarian algorithm to find the maximum score by finding the minimum cost assignment of the cells to the values in the grid. We can then return the maximum score as the result.
class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Map every distinct value to a column on the right side.
        unordered_map<int, int> id;
        vector<int> values;

        for (auto &row : grid)
        {
            for (int x : row)
            {
                if (!id.count(x))
                {
                    id[x] = (int)values.size() + 1; // 1-indexed
                    values.push_back(x);
                }
            }
        }

        int k = values.size();

        // We add n dummy columns. Matching a row to a dummy means:
        // "do not choose any cell from this row", with weight 0.
        int m = k + n;

        const long long BIG = (long long)1e15;
        vector<vector<long long>> cost(n + 1, vector<long long>(m + 1, BIG));

        // Real value columns.
        for (int i = 0; i < n; i++)
        {
            for (int x : grid[i])
            {
                int j = id[x];
                cost[i + 1][j] = -x; // maximize x <=> minimize -x
            }
        }

        // Dummy columns.
        for (int i = 1; i <= n; i++)
        {
            for (int j = k + 1; j <= m; j++)
            {
                cost[i][j] = 0;
            }
        }

        // Hungarian algorithm for rectangular min-cost assignment.
        // n rows, m columns, with n <= m.
        vector<long long> u(n + 1), v(m + 1);
        vector<int> p(m + 1), way(m + 1);

        for (int i = 1; i <= n; i++)
        {
            p[0] = i;
            int j0 = 0;

            vector<long long> minv(m + 1, BIG);
            vector<char> used(m + 1, false);

            do
            {
                used[j0] = true;
                int i0 = p[j0];
                long long delta = BIG;
                int j1 = 0;

                for (int j = 1; j <= m; j++)
                {
                    if (used[j])
                        continue;

                    long long cur = cost[i0][j] - u[i0] - v[j];

                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }

                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }

                for (int j = 0; j <= m; j++)
                {
                    if (used[j])
                    {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    }
                    else
                    {
                        minv[j] -= delta;
                    }
                }

                j0 = j1;
            } while (p[j0] != 0);

            do
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }

        long long minCost = 0;

        for (int j = 1; j <= m; j++)
        {
            if (p[j] != 0)
            {
                minCost += cost[p[j]][j];
            }
        }

        return (int)(-minCost);
    }
};
