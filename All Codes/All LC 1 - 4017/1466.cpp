// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Create a vector offset of size n + 1 to store the number of connections for each city.
    //  2. Iterate through the connections and increment the count for both cities in the offset vector.
    //  3. Move all values in the offset vector up by one position to prepare for prefix sum calculation.
    //  4. Calculate the prefix sum of the offset vector to determine the starting index for each city's connections in the edges vector.
    //  5. Create a vector edges of pairs to store the connections and their direction (true for original direction, false for reversed).
    //  6. Copy the starting positions from the offset vector to a pointer vector ptr.
    //  7. Iterate through the connections again and populate the edges vector with the connections and their direction, updating the ptr vector accordingly.
    //  8. Use a queue to perform a breadth-first search (BFS) starting from city 0. Mark city 0 as visited and initialize a flips counter to 0.
    //  9. While the queue is not empty, dequeue a city and iterate through its connections in the edges vector. For each unvisited connected city, mark it as visited, increment the flips counter if the connection is in the original direction, and enqueue the connected city.
    //  10. Return the total number of flips needed to make all paths lead to city 0.
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<int> offset(n + 1);

        // Calculate counts
        for (auto &c : connections)
        {
            offset[c[0]]++;
            offset[c[1]]++;
        }

        // Move all vals up one
        for (int i = n; i > 0; i--)
            offset[i] = offset[i - 1];

        offset[0] = 0;

        // Incremental add
        for (int i = 1; i <= n; i++)
            offset[i] += offset[i - 1];

        vector<pair<int, bool>> edges(connections.size() * 2, {-1, false});

        // Copy start positions from offset
        vector<int> ptr(offset);

        for (auto &e : connections)
        {
            edges[ptr[e[0]]] = {e[1], true};
            edges[ptr[e[1]]] = {e[0], false};
            ptr[e[0]]++;
            ptr[e[1]]++;
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int flips = 0;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (auto e = &edges[offset[x]]; e != &edges[offset[x + 1]]; e++)
            {
                if (!visited[e->first])
                {
                    visited[e->first] = true;

                    if (e->second)
                        flips++;

                    q.push(e->first);
                }
            }
        }

        return flips;
    }
};