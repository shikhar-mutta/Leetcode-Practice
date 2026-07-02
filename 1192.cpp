// Link: https://leetcode.com/problems/critical-connections-in-a-network/description/

#include <bits/stdc++.h>
using namespace std;

// 100th Percentile Competitive Programming Template
// Constraints: n <= 10^5, connections <= 10^5

const int MAXN = 100005;
const int MAXE = 100005 * 2;

int head[MAXN + 1];
int cur_head[MAXN + 1];
int edges[MAXE];
int edge_ids[MAXE];
int disc[MAXN];
int low[MAXN];

struct Frame
{
    int u, p_edge, i;
};
Frame stk[MAXN];

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        int e = connections.size();

        // 1. Strict State Reset
        for (int i = 0; i < n; ++i)
        {
            head[i] = 0;
            disc[i] = -1;
            low[i] = -1;
        }
        // Note: head[n] (the sentinel) is not zeroed here because the
        // prefix sum loop unconditionally overwrites it.

        // 2. CSR Construction
        for (int i = 0; i < e; ++i)
        {
            head[connections[i][0]]++;
            head[connections[i][1]]++;
        }

        int sum = 0;
        for (int i = 0; i <= n; ++i)
        {
            int count = head[i];
            head[i] = sum;

            // cur_head is naturally reinitialized here for the current test case,
            // entirely wiping any stale state without needing a dedicated reset loop.
            cur_head[i] = sum;
            sum += count;
        }

        // Populate forward using the mutable cursor.
        for (int i = 0; i < e; ++i)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            int pos_u = cur_head[u]++;
            edges[pos_u] = v;
            edge_ids[pos_u] = i;

            int pos_v = cur_head[v]++;
            edges[pos_v] = u;
            edge_ids[pos_v] = i;
        }

        vector<vector<int>> result;
        int timer = 0;
        int top = 0;

        // 3. DFS Execution
        for (int start = 0; start < n; ++start)
        {
            if (disc[start] != -1)
                continue;

            disc[start] = low[start] = ++timer;
            stk[top++] = {start, -1, head[start]};

            while (top > 0)
            {
                Frame &f = stk[top - 1];
                int u = f.u;
                int p_edge = f.p_edge;

                if (f.i < head[u + 1])
                {
                    int idx = f.i++;
                    int v = edges[idx];
                    int e_id = edge_ids[idx];

                    if (e_id == p_edge)
                        continue;

                    if (disc[v] == -1)
                    {
                        disc[v] = low[v] = ++timer;
                        stk[top++] = {v, e_id, head[v]};
                    }
                    else
                    {
                        if (disc[v] < low[u])
                            low[u] = disc[v];
                    }
                }
                else
                {
                    int popped_u = stk[--top].u;

                    if (top > 0)
                    {
                        int pu = stk[top - 1].u;
                        if (low[popped_u] < low[pu])
                            low[pu] = low[popped_u];

                        if (low[popped_u] > disc[pu])
                        {
                            result.push_back({pu, popped_u});
                        }
                    }
                }
            }
        }

        return result;
    }
};
