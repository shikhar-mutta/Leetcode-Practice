// Link: https://leetcode.com/problems/maximum-profit-from-valid-topological-order-in-dag/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n! * n^2) where n is the number of nodes in the graph. The worst case occurs when the graph is a complete DAG, and we have to explore all possible topological orders. For each topological order, we calculate the score which takes O(n^2) time due to the sorting step.
// SC: O(n^2) for the visited map and the recursion stack. The visited map can store up to n! different states, and each state is represented by a string of length n. The recursion stack can go up to n levels deep in the worst case.
// Approach: The solution uses a depth-first search (DFS) approach to explore all possible topological orders of the directed acyclic graph (DAG). It maintains an indegree array to track the number of incoming edges for each node. The algorithm recursively selects nodes with zero indegree, updates the indegree of their neighbors, and calculates the score based on the current position in the topological order. It uses memoization to store previously computed states to avoid redundant calculations.
class Solution
{

    int dfs(vector<vector<int>> const &graph, vector<int> &indegree,
            vector<int> const &scores, int position, string &state,
            unordered_map<string, int> &visited)
    {

        if (visited.find(state) != visited.end())
        {
            return visited[state];
        }

        bool const hasIndgreeNodes = any_of(begin(indegree), end(indegree),
                                            [](int const &i)
                                            { return i > 0; });

        int maxScore = {};

        if (!hasIndgreeNodes)
        {
            vector<int> score;
            for (int i = 0; i < size(indegree); ++i)
            {
                if (indegree[i] == 0)
                {
                    score.push_back(scores[i]);
                }
            }
            sort(begin(score), end(score));
            for (auto s : score)
            {
                maxScore += (s * position++);
            }
            return visited[state] = maxScore;
        }

        for (int i = 0; i < size(indegree); ++i)
        {
            if (indegree[i] != 0)
                continue;
            indegree[i]--;
            for (auto const &n : graph[i])
            {
                indegree[n]--;
            }

            state[i] = 'X';

            int const score =
                position * scores[i] +
                dfs(graph, indegree, scores, position + 1, state, visited);
            maxScore = max(maxScore, score);

            state[i] = ' ';

            for (auto const &n : graph[i])
            {
                indegree[n]++;
            }
            indegree[i]++;
        }

        return visited[state] = maxScore;
    }

public:
    int maxProfit(int const n, vector<vector<int>> const &edges,
                  vector<int> const &scores)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto const &edge : edges)
        {
            int const &u = edge[0];
            int const &v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        string state(n, ' ');
        unordered_map<string, int> visited;
        return dfs(graph, indegree, scores, 1, state, visited);
    }
};