// Link: https://leetcode.com/problems/node-with-highest-edge-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of nodes in the graph.
// SC: O(n), where n is the number of nodes in the graph.
// Approach:
//  1. We initialize a vector scores of size n, initialized to 0, which will be used to store the edge scores for each node in the graph. The edge score for a node is defined as the sum of the indices of all nodes that have an edge pointing to it.
//  2. We iterate through each node i in the graph and update the edge score for the node that it points to (edges[i]) by adding the index i to scores[edges[i]].
//  3. After calculating the edge scores for all nodes, we initialize two variables mx and idx to keep track of the maximum edge score and the index of the node with the highest edge score, respectively.
//  4. We iterate through the scores vector and update mx and idx whenever we find a node with a higher edge score than the current maximum. If there are multiple nodes with the same maximum edge score, we will keep the one with the smallest index, as we are iterating from left to right.
//  5. Finally, we return the index of the node with the highest edge score.
class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        int n = edges.size();
        vector<long long> scores(n, 0);

        for (int i = 0; i < n; i++)
        {
            scores[edges[i]] += i;
        }

        long long mx = -1;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (scores[i] > mx)
            {
                mx = scores[i];
                idx = i;
            }
        }

        return idx;
    }
};