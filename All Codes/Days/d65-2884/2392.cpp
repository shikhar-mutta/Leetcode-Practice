// Link: https://leetcode.com/problems/build-a-matrix-with-conditions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k + r + c), SC: O(k + r + c)
// Approach: Use topological sort to determine the order of rows and columns based on the given conditions. If a valid order exists for both rows and columns, construct the matrix accordingly. If not, return an empty matrix.
// Helper function to perform topological sort using Kahn's Algorithm   
class Solution
{
private:
    // Helper function to perform topological sort using Kahn's Algorithm
    std::vector<int> topoSort(int k,
                              const std::vector<std::vector<int>> &conditions)
    {
        std::vector<std::vector<int>> adj(k + 1);
        std::vector<int> inDegree(k + 1, 0);

        for (const auto &cond : conditions)
        {
            int u = cond[0];
            int v = cond[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        std::queue<int> q;
        for (int i = 1; i <= k; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        std::vector<int> order;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int neighbor : adj[curr])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // If topological sort includes all k nodes, return the order;
        // otherwise, a cycle exists
        if (order.size() == k)
        {
            return order;
        }
        return {};
    }

public:
    std::vector<std::vector<int>>
    buildMatrix(int k, std::vector<std::vector<int>> &rowConditions,
                std::vector<std::vector<int>> &colConditions)
    {
        std::vector<int> rowOrder = topoSort(k, rowConditions);
        std::vector<int> colOrder = topoSort(k, colConditions);

        // If either ordering has a cycle, it's impossible to build the matrix
        if (rowOrder.empty() || colOrder.empty())
        {
            return {};
        }

        // Map each value (1 to k) to its row and column positions
        std::vector<int> rowPos(k + 1);
        std::vector<int> colPos(k + 1);

        for (int i = 0; i < k; ++i)
        {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        // Construct the k x k matrix initialized to 0
        std::vector<std::vector<int>> matrix(k, std::vector<int>(k, 0));

        for (int val = 1; val <= k; ++val)
        {
            matrix[rowPos[val]][colPos[val]] = val;
        }

        return matrix;
    }
};
