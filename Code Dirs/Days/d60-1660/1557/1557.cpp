// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach:
    //   1. We will keep track of the indegree of each node in the graph.
    //   2. We will iterate through the edges and for each edge, we will increment the indegree of the destination node.
    //   3. We will then iterate through the indegree array and for each node with indegree 0, we will add it to the answer.
    //   4. We will return the answer.
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n, 0);

        for (auto &e : edges)
            indegree[e[1]]++;

        vector<int> ans;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
