// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//  1. We first build a tree representation of the company hierarchy using an adjacency list, where each employee is a node and the edges represent the manager-subordinate relationships. We create a vector of vectors called children, where children[i] contains the list of employees directly managed by employee i.
//  2. We then perform a depth-first search (DFS) traversal of the tree starting from the headID (the root of the tree). For each employee, we recursively calculate the time needed to inform all their subordinates. We keep track of the maximum time needed among all subordinates and add the informTime of the current employee to it. This gives us the total time needed to inform all employees under the current employee.
//  3. Finally, we return the total time needed to inform all employees starting from the headID, which is the result of the DFS traversal.
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager,
                     vector<int> &informTime)
    {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i)
            if (manager[i] != -1)
                children[manager[i]].push_back(i);
        return dfs(headID, children, informTime);
    }

private:
    int dfs(int u, vector<vector<int>> &children, vector<int> &informTime)
    {
        int mx = 0;
        for (int v : children[u])
            mx = max(mx, dfs(v, children, informTime));
        return informTime[u] + mx;
    }
};