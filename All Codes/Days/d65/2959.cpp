// Link: https://leetcode.com/problems/number-of-possible-sets-of-closing-branches/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n^3), SC: O(n^2)
// Approach: We can use a bitmasking approach to generate all possible subsets of the given roads. For each subset, we can check if the maximum distance between any two cities in the subset is less than or equal to the given maxDistance. We can use the Floyd-Warshall algorithm to calculate the shortest distances between all pairs of cities. If a subset satisfies the distance condition, we increment our answer. Finally, we return the total count of valid subsets.
class Solution
{
public:
    int e[10][10], d[10][10];
    bool check(int n, int g, int maxDistance)
    {
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                d[i][j] = d[j][i] = 1e9;
        for (int i = 0; i < n; ++i)
        {
            if (g & (1 << i))
            {
                for (int j = 0; j < i; ++j)
                {
                    if (g & (1 << j))
                        for (int k = 0; k < i; ++k)
                        {
                            if (g & (1 << k))
                                d[i][j] = d[j][i] =
                                    min(d[j][i], d[j][k] + e[k][i]);
                        }
                }
                for (int j = 0; j < i; ++j)
                {
                    if (g & (1 << j))
                        for (int k = 0; k < i; ++k)
                        {
                            if (g & (1 << k))
                                d[j][k] = d[k][j] =
                                    min(d[k][j], d[j][i] + d[i][k]);
                        }
                }
                d[i][i] = 0;
            }
        }
        for (int i = 0; i < n; ++i)
            if (g & (1 << i))
                for (int j = i + 1; j < n; ++j)
                    if (g & (1 << j) && d[i][j] > maxDistance)
                        return 0;
        return 1;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                e[i][j] = e[j][i] = 1e9;
        for (int i = 0; i < roads.size(); ++i)
        {
            int a = roads[i][0], b = roads[i][1];
            e[b][a] = e[a][b] = min(e[a][b], roads[i][2]);
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i)
            if (check(n, i, maxDistance))
                ++ans;
        return ans;
    }
};
