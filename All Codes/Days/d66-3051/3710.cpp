// Link: https://leetcode.com/problems/maximum-partition-factor/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * log(max_distance)) where n is the number of points and max_distance is the maximum distance between any two points.
// SC: O(n^2) where n is the number of points.
// Approach:
// 1. We can use binary search to find the maximum partition factor.
// 2. We can use a helper function to check if the graph is bipartite for a given distance.
// 3. We can use a 2D array to store the distances between all pairs of points.
// 4. We can use a recursive function to check if the graph is bipartite for a given distance.
// 5. We can use a color array to store the colors of the vertices in the graph.
// 6. We can iterate through all pairs of points and check if the distance between them is less than the given distance. If it is, we can add an edge between the two points in the graph.
// 7. We can check if the graph is bipartite for the given distance. If it is, we can update the maximum partition factor. If it is not, we can update the minimum partition factor.
#define forn(i, n) for (int i = 0; i < n; ++i)
int d[500][500], c[500];
bool is_bip(int n, int m)
{
    auto dfs = [n, m](this auto &&dfs, int v, int cc = 1) -> bool
    {
        c[v] = cc;
        forn(u, n) if (u != v && d[v][u] < m &&
                       (c[u] == cc || !c[u] && !dfs(u, 3 - cc))) return false;
        return true;
    };
    fill_n(c, n, 0);
    forn(i, n) if (!c[i] && !dfs(i)) return false;
    return true;
}
int mh(auto &a, auto &b) { return abs(a[0] - b[0]) + abs(a[1] - b[1]); }

class Solution
{
public:
    int maxPartitionFactor(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 2)
            return 0;

        forn(i, n) forn(j, i) d[j][i] = d[i][j] = mh(points[i], points[j]);

        int l = 0, r = INT_MAX;
        while (r - l > 1)
        {
            int m = (r + l) / 2;
            (is_bip(n, m) ? l : r) = m;
        }

        return l;
    }
};
