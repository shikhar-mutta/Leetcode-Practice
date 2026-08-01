// Link: https://leetcode.com/problems/construct-2d-grid-matching-graph-layout/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n^2)  SC: O(n)
// Approach: The problem is to construct a 2D grid layout of a graph such that
// the edges of the graph match the adjacency of the grid. The solution involves
// first building the graph from the given edges. Then, we randomly choose a node with the minimum degree as the corner of the grid. We then construct the first row of the grid by appending neighbors of the corner node until we hit another corner. After constructing the first row, we fill in the rest of the grid by iterating through the rows and columns, and for each cell, we find an unvisited neighbor of the node in the previous row and mark it as seen. Finally, we return the constructed grid layout. The time complexity is O(n^2) due to the nested loops for filling the grid, and the space complexity is O(n) for storing the graph and the seen nodes.   
class Solution
{
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);

        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Randomly choose a node with the minimum degree as the corner.
        const int corner =
            ranges::min_element(graph, ranges::less{}, &vector<int>::size) -
            graph.begin();

        vector<bool> seen(n);
        seen[corner] = true;
        const vector<int> firstRow = getFirstRow(graph, corner, seen);
        const int cols = firstRow.size();
        const int rows = n / cols;

        vector<vector<int>> ans(rows, vector<int>(cols));
        ans[0] = firstRow;

        for (int i = 1; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                for (const int v : graph[ans[i - 1][j]])
                    if (!seen[v])
                    {
                        ans[i][j] = v;
                        seen[v] = true;
                        break;
                    }

        return ans;
    }

private:
    vector<int> getFirstRow(vector<vector<int>> &graph, int corner,
                            vector<bool> &seen)
    {
        const int cornerDegree = graph[corner].size();
        vector<int> row = {corner};

        // Continue appending neighbors until we hit another corner.
        while (row.size() == 1 || graph[row.back()].size() == cornerDegree + 1)
        {
            // Sort neighbors by degree to prioritize smaller ones (shortest row built
            // first).
            vector<int> &neighbors = graph[row.back()];
            ranges::sort(neighbors, ranges::less{},
                         [&graph](int v)
                         { return graph[v].size(); });
            for (const int v : neighbors)
                if (!seen[v] && (graph[v].size() == cornerDegree ||
                                 graph[v].size() == cornerDegree + 1))
                {
                    row.push_back(v);
                    seen[v] = true;
                    break;
                }
        }

        return row;
    }
};