// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)  SC: O(n * 2^n)
// Approach: Use BFS to explore all possible states of the graph. Each state is represented by a bitmask indicating which nodes have been visited and the current node. Start BFS from all nodes, and for each state, explore its neighbors to create new states. Keep track of visited states to avoid revisiting them. The first time we reach a state where all nodes have been visited, we return the number of steps taken.
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();

        if (n <= 1)
            return 0;
        if (n == 2)
            return 1;

        int finalMask = (1 << n) - 1;

        // n <= 12，所以最多狀態數 = 12 * 4096 = 49152
        int q[50000];
        int head = 0, tail = 0;

        // visited[mask] 的每個 bit 表示該 node 是否在這個 mask 狀態出現過
        uint16_t visited[4096] = {};

        for (int node = 0; node < n; node++)
        {
            int mask = 1 << node;

            visited[mask] |= (1 << node);

            // state = mask 放高位，node 放低 4 bits
            q[tail++] = (mask << 4) | node;
        }

        int steps = 0;

        while (head < tail)
        {
            int levelEnd = tail;

            while (head < levelEnd)
            {
                int state = q[head++];

                int node = state & 15;
                int mask = state >> 4;

                for (int nei : graph[node])
                {
                    int nextMask = mask | (1 << nei);

                    if (nextMask == finalMask)
                    {
                        return steps + 1;
                    }

                    uint16_t nodeBit = 1 << nei;

                    if ((visited[nextMask] & nodeBit) == 0)
                    {
                        visited[nextMask] |= nodeBit;
                        q[tail++] = (nextMask << 4) | nei;
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};