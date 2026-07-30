// Link: https://leetcode.com/problems/cycle-length-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(Q * logN), SC: O(1)
// Approach: The problem is to find the length of the cycle formed by adding an edge between two nodes in a tree. The solution involves finding the lowest common ancestor (LCA) of the two nodes and calculating the distance from each node to the LCA. The total length of the cycle is then the sum of these distances plus one for the added edge. The solution uses a while loop to traverse up the tree until both nodes meet at their LCA, counting the steps taken.
class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto &q : queries)
        {
            long long a = q[0], b = q[1];
            int steps = 0;
            while (a != b)
            {
                if (a > b)
                    a /= 2;
                else
                    b /= 2;
                steps++;
            }
            ans.push_back(steps + 1);
        }
        return ans;
    }
};
