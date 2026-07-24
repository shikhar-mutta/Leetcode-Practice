// Link: https://leetcode.com/problems/course-schedule-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n^2)
// Approach:
//  1. Create an adjacency list adjrel to represent the prerequisite relationships between courses.
//  2. For each query, perform a depth-first search (DFS) starting from the first course in the query to check if there is a path to the second course in the query.
//  3. Use a visited array vis to keep track of the courses that have already been visited during the DFS to avoid cycles and redundant checks.
//  4. If a path is found from the first course to the second course, return true for that query; otherwise, return false.
//  5. Repeat the process for all queries and return the results as a vector of boolean values.
class Solution
{
public:
    bool dfs(int start, int target, vector<int> &vis,
             vector<vector<int>> &adjrel)
    {
        if (start == target)
        {
            return true;
        }
        if (!adjrel[start].size())
        {
            return false;
        }
        if (vis[start] == 1)
        {
            return false;
        }
        vis[start] = 1;
        for (int i : adjrel[start])
        {
            if (dfs(i, target, vis, adjrel))
            {
                return true;
            }
        }
        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries)
    {
        vector<vector<int>> adjrel(numCourses);
        for (auto &i : prerequisites)
        {
            adjrel[i[0]].push_back(i[1]);
        }
        // dfs

        vector<bool> ans;
        for (auto i : queries)
        {
            vector<int> vis(numCourses, 0);
            ans.push_back(dfs(i[0], i[1], vis, adjrel));
        }
        return ans;
    }
};