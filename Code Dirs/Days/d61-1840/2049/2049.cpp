// Link: https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //   Approach:
    //   1. We can use DFS to calculate the size of the subtree for each node and the score for each node.
    //   2. We can use an array to store the size of the subtree for each node and a variable to store the maximum score and the count of nodes with the maximum score.
    //   3. We can iterate through the parents array to build the adjacency list for the tree.
    //   4. We can then perform DFS to calculate the size of the subtree for each node and the score for each node. If the score is greater than the maximum score, we update the maximum score and reset the count to 1.
    //   5. If the score is equal to the maximum score, we increment the count. Finally, we return the count of nodes with the maximum score.
    int countHighestScoreNodes(vector<int> &parents)
    {
        const int n{static_cast<int>(parents.size())};
        static pair<int, int> adj[100000]{};
    memset(adj, 0, sizeof(pair<int, int>) * n);
    for (int i{1}; i < n; ++i)
    {
        const int j{parents[i]};
        (adj[j].first ? adj[j].second : adj[j].first) = i;
    }
    long long res{0};
    int cnt{0};
    auto dfs{[&](this auto &&dfs, int i) -> int
             {
                 const int l{adj[i].first ? dfs(adj[i].first) : 0},
                     r{adj[i].second ? dfs(adj[i].second) : 0};
                 long long mx{1};
                 if (i)
                     mx *= n - l - r - 1;
                 if (l)
                     mx *= l;
                 if (r)
                     mx *= r;
                 if (mx > res)
                 {
                     res = mx;
                     cnt = 1;
                 }
                 else if (mx == res)
                     ++cnt;
                 return l + r + 1;
             }};
    dfs(0);
    return cnt;
}
}
;
