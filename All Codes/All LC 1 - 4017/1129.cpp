// Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(V+E) where V is the number of vertices and E is the number of edges.
    // SC: O(V+E) where V is the number of vertices and E is the number of edges.
    // Approach:
    //  1. We can use a BFS approach to find the shortest path with alternating colors.
    //  2. We can use two adjacency lists to store the red and blue edges separately.
    //  3. We can use a queue to perform the BFS and keep track of the current node, distance, and color of the previous edge.
    //  4. We can use two visited arrays to keep track of the visited nodes for red and blue edges separately.
    //  5. We can initialize the queue with the starting node (0) and distance (0)
    //  6. We can perform the BFS until the queue is empty and update the answer array with the shortest distance for each node.
    //  7. Finally, we can return the answer array which contains the shortest distance for each node.
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<int>> adjRed(n), adjBlue(n);
        for (auto i : redEdges)
        {
            adjRed[i[0]].push_back(i[1]);
        }
        for (auto i : blueEdges)
        {
            adjBlue[i[0]].push_back(i[1]);
        }
        queue<array<int, 3>> q; //{node, dist, colour of previous edge}
        q.push({0, 0, 0});
        q.push({0, 0, 1});
        vector<int> visRed(n, 0), visBlue(n, 0);
        vector<int> ans(n, -1);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int node = curr[0];
            int dist = curr[1];
            int stat = curr[2];
            if (ans[node] == -1)
                ans[node] = dist;
            if (stat == 0)
            { // means previous was red
                for (auto adjNode : adjBlue[node])
                {
                    if (visBlue[adjNode] != 1)
                    {
                        q.push({adjNode, dist + 1, 1});
                        visBlue[adjNode] = 1;
                    }
                }
            }
            else
            {
                for (auto adjNode : adjRed[node])
                {
                    if (visRed[adjNode] != 1)
                    {
                        q.push({adjNode, dist + 1, 0});
                        visRed[adjNode] = 1;
                    }
                }
            }
        }
        return ans;
    }
};