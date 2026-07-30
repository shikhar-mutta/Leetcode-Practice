// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) where n is the number of cities and q is the number of queries
// SC: O(n) where n is the number of cities
// Approach: We can use a next array to keep track of the next city that can be reached from each city. Initially, the next array is initialized such that next[i] = i + 1 for all cities except the last one, which has next[n - 1] = -1. For each query, we check if the current city u can reach city v directly or indirectly. If it can, we update the next array to reflect the new road addition and decrease the distance accordingly. Finally, we return the updated distances after processing all queries.
class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        vector<int> next(n);
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
        int dist = n - 1;
        vector<int> ans;
        for (auto &q : queries)
        {
            int u = q[0];
            int v = q[1];
            // If u already jumps beyond or exactly to v,
            // this query changes nothing.
            if (next[u] == -1 || next[u] >= v)
            {
                ans.push_back(dist);
                continue;
            }
            int cur = next[u];
            while (cur != -1 && cur < v)
            {
                dist--;
                int nxt = next[cur];
                next[cur] = -1;
                cur = nxt;
            }
            next[u] = v;
            ans.push_back(dist);
        }
        return ans;
    }
};