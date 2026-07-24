// Link: https://leetcode.com/problems/find-center-of-star-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach: Hashing
//    1. We can use a hash map to store the count of each node in the edges.
//    2. The node with the count equal to the number of edges is the center of the star graph.
//    3. We can return that node as the center of the star graph.
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
                   ? edges[0][0]
                   : edges[0][1];
    }
};
