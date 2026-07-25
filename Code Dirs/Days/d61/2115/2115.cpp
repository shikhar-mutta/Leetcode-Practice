// Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the number of recipes and m is the total number of ingredients across all recipes.
// SC: O(n + m), where n is the number of recipes and m is the total number of ingredients across all recipes.
// Approach:
//   1. We first create an adjacency list to represent the dependencies between recipes and their ingredients. We also create an indegree array to keep track of the number of ingredients required for each recipe.
//   2. We then initialize a queue with the initial supplies and perform a topological sort-like process. For each supply, we check which recipes can be made using that supply and decrement their indegree. If a recipe's indegree reaches zero, it means all its ingredients are available, and we can add it to the queue and the answer list.
//   3. Finally, we return the list of recipes that can be made with the given supplies.
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies)
    {
        int n = recipes.size();
        unordered_map<string, vector<int>> adjList;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            int size = ingredients[i].size();
            indegree[i] = size;

            for (auto ing : ingredients[i])
            {
                adjList[ing].push_back(i);
            }
        }

        queue<string> q;
        for (auto s : supplies)
        {
            q.push(s);
        }

        vector<string> ans;
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            for (int nb : adjList[curr])
            {
                indegree[nb]--;
                if (indegree[nb] == 0)
                {
                    q.push(recipes[nb]);
                    ans.push_back(recipes[nb]);
                }
            }
        }
        return ans;
    }
};