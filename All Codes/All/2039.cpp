// Link: https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//  1. We can use a queue to perform a breadth-first search (BFS)
//  2. We can use an array to store the distance of each node from the master server (node 0).
//  3. We can use a for loop to iterate through the queue and update the distance of each node from the master server.
//  4. We can use a for loop to iterate through the patience array and calculate the time when the network becomes idle for each node
//  5. We can return the maximum time when the network becomes idle for all nodes.
//  6. We can return the maximum time when the network becomes idle for all nodes.
class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        const int n{static_cast<int>(patience.size())};
        static int from[100001]{}, to[200000]{};
        memset(from, 0, sizeof(int) * n);
        for (const vector<int> &e : edges)
        {
            const int u{e[0]}, v{e[1]};
            ++from[u];
            ++from[v];
        }
        exclusive_scan(from, from + n, from, 0);
        for (const vector<int> &e : edges)
        {
            const int u{e[0]}, v{e[1]};
            to[from[u]++] = v;
            to[from[v]++] = u;
        }
        from[n] = from[n - 1];
        for (int i{n - 1}; i > 0; --i)
            from[i] = from[i - 1];
        from[0] = 0;
        queue<int> q{};
        for (int i{from[0]}; i < from[1]; ++i)
        {
            const int j{to[i]};
            patience[j] = -patience[j];
            q.push(j);
        }
        int res{0};
        for (int d{1}; !q.empty(); ++d)
        {
            for (int sz{static_cast<int>(q.size())}; sz > 0; --sz)
            {
                const int i{q.front()};
                q.pop();
                res = max(res, (2 * d - 1) / patience[i] * patience[i] + 2 * d);
                for (int idx{from[i]}; idx < from[i + 1]; ++idx)
                {
                    const int j{to[idx]};
                    if (patience[j] > 0)
                    {
                        q.push(j);
                        patience[j] = -patience[j];
                    }
                }
            }
        }
        return res + 1;
    }
};