// Link: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V)  SC: O(V + E)
//  Approach: Dijkstra's algorithm to find the shortest distance from node 0 to all other nodes. For each edge, we can reach at most min(cnt, maxMoves - dist[u]) new nodes on that edge. If we can reach the other endpoint of the edge, we can also count that node as reachable.
class Solution
{
private:
    class Edge
    {
        friend class Solution;
        int to, cnt;
        int next;

    public:
        Edge() {}
    };
    vector<Edge> e;
    int ecnt;
    vector<int> hd;
    inline void init(int vnum, int _enum)
    {
        e.resize((_enum << 1) + 66);
        ecnt = 2;
        hd.resize(vnum, 0);
    }
    inline void ae(int u, int v, int cnt)
    {
        e[ecnt].to = v, e[ecnt].cnt = cnt;
        e[ecnt].next = hd[u];
        hd[u] = ecnt;
        ecnt++;
    }
    inline void bae(int u, int v, int cnt) { ae(u, v, cnt), ae(v, u, cnt); }
    class PNode
    {
    public:
        int v, p;
        PNode(int v, int p) : v(v), p(p) {}
    };
    class Cmp
    {
    public:
        bool operator()(PNode &a, PNode &b) { return a.p > b.p; }
    };

public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        init(n, edges.size());
        for (vector<int> &edge : edges)
        {
            bae(edge[0], edge[1], edge[2]);
        }
        priority_queue<PNode, vector<PNode>, Cmp> q;
        vector<int> dist(n, 0x7fffffff);
        vector<bool> vis(n, false);
        int res = 1;
        dist[0] = 0;
        vis[0] = true;
        q.push(PNode(0, 0));
        while (q.size())
        {
            int v = q.top().v;
            int d = q.top().p;
            q.pop();
            if (d != dist[v])
                continue;
            if (d > maxMoves)
                break;
            for (int i = hd[v]; i; i = e[i].next)
            {
                if (d + e[i].cnt + 1 < dist[e[i].to])
                {
                    dist[e[i].to] = d + e[i].cnt + 1;
                    q.push(PNode(e[i].to, dist[e[i].to]));
                }
                int add = min(e[i].cnt, maxMoves - d);
                res += add;
                if (d + e[i].cnt + 1 <= maxMoves && (!vis[e[i].to]))
                {
                    res++;
                    vis[e[i].to] = true;
                }
                e[i ^ 1].cnt -= add;
            }
        }
        return res;
    }
};