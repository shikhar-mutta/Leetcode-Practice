// Link: https://leetcode.com/problems/minimize-malware-spread-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: DSU. Build connected components, count infected nodes in each component. If a component has only one infected node, removing it will save the entire component. Return the node that saves the most nodes (tie-breaker: smallest index).
class UnionFind
{
public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        componentSize = vector<int>(n, 1);
        // Initialize each node as its own parent
        iota(parent.begin(), parent.end(), 0);
    }

    // Unite two components, return true if they were in different components
    bool unite(int nodeA, int nodeB)
    {
        int rootA = find(nodeA);
        int rootB = find(nodeB);

        // Already in the same component
        if (rootA == rootB)
        {
            return false;
        }

        // Union by size: attach smaller tree under root of larger tree
        if (componentSize[rootA] > componentSize[rootB])
        {
            parent[rootB] = rootA;
            componentSize[rootA] += componentSize[rootB];
        }
        else
        {
            parent[rootA] = rootB;
            componentSize[rootB] += componentSize[rootA];
        }
        return true;
    }

    // Find root of component with path compression
    int find(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    // Get size of the component containing the given root
    int getSize(int root) { return componentSize[root]; }

private:
    vector<int> parent;        // Parent array for union-find
    vector<int> componentSize; // Size of each component
};

class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();

        // Mark initially infected nodes
        bool isInfected[n];
        memset(isInfected, false, sizeof(isInfected));
        for (int node : initial)
        {
            isInfected[node] = true;
        }

        // Build union-find for non-infected nodes
        UnionFind uf(n);
        for (int i = 0; i < n; ++i)
        {
            if (!isInfected[i])
            {
                for (int j = i + 1; j < n; ++j)
                {
                    // Connect non-infected nodes that have an edge
                    if (graph[i][j] && !isInfected[j])
                    {
                        uf.unite(i, j);
                    }
                }
            }
        }

        // For each infected node, find which non-infected components it
        // connects to
        unordered_set<int> connectedComponents[n];
        // Count how many infected nodes connect to each component
        int componentInfectionCount[n];
        memset(componentInfectionCount, 0, sizeof(componentInfectionCount));

        for (int infectedNode : initial)
        {
            // Find all non-infected components this infected node connects to
            for (int j = 0; j < n; ++j)
            {
                if (!isInfected[j] && graph[infectedNode][j])
                {
                    connectedComponents[infectedNode].insert(uf.find(j));
                }
            }
            // Increment count for each connected component
            for (int componentRoot : connectedComponents[infectedNode])
            {
                ++componentInfectionCount[componentRoot];
            }
        }

        // Find the best node to remove (minimize final infection spread)
        int bestNodeToRemove = 0;
        int maxNodesSaved = -1;

        for (int infectedNode : initial)
        {
            int nodesSaved = 0;

            // Count nodes that would be saved by removing this infected node
            for (int componentRoot : connectedComponents[infectedNode])
            {
                // Only count components that are connected to exactly one
                // infected node
                if (componentInfectionCount[componentRoot] == 1)
                {
                    nodesSaved += uf.getSize(componentRoot);
                }
            }

            // Update best choice (maximize saved nodes, minimize node index on
            // tie)
            if (nodesSaved > maxNodesSaved ||
                (nodesSaved == maxNodesSaved &&
                 infectedNode < bestNodeToRemove))
            {
                bestNodeToRemove = infectedNode;
                maxNodesSaved = nodesSaved;
            }
        }

        return bestNodeToRemove;
    }
};