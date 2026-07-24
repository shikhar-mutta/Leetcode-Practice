// Link: https://leetcode.com/problems/path-with-maximum-probability/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), SC: O(n + m)
    //   Approach:
    //   1. Initialize a vector maxProb of size n to store the maximum probability of reaching each node from the start_node. Set the probability of the start_node to 1.
    //   2. Iterate n-1 times (where n is the number of nodes) to relax the edges and update the maximum probabilities.
    //   3. For each edge, check if the probability of reaching the destination node through the current edge is greater than the current maximum probability for that node. If it is, update the maximum probability for that node.
    //   4. If no updates were made in an iteration, break the loop early as further iterations will not yield any new maximum probabilities.
    //   5. Return the maximum probability of reaching the end_node from the start_node.
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node)
    {
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        for (int i = 0; i < n - 1; ++i)
        {
            bool updated = false;
            for (int j = 0; j < edges.size(); ++j)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (maxProb[u] * prob > maxProb[v])
                {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;
                }
                if (maxProb[v] * prob > maxProb[u])
                {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }
            if (!updated)
                break;
        }

        return maxProb[end_node];
    }
};
