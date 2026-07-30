// Link: https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use a depth-first search (DFS) approach to find the longest cycle in the graph. We maintain a visited array to keep track of the nodes we have already visited.
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int time = 0, ans = -1, n = edges.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;

            int next = i;
            int start = time;
            while (next != -1 && vis[next] == 0)
            {
                vis[next] = time++;
                next = edges[next];
            }

            // if we find a cycle (vis[next] != 0)
            if (next != -1 && vis[next] >= start)
            {
                ans = max(ans, time - vis[next]);
            }
        }

        return ans;
    }
};
