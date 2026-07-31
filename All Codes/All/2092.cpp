// Link: https://leetcode.com/problems/find-all-people-with-secret/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n + m) * log(n)), SC: O(n + m)
// Approach: Dijkstra's algorithm
//  We can model the problem as a graph where each person is a node and each meeting is an edge with a weight equal to the time of the meeting.
//  We can then use Dijkstra's algorithm to find the earliest time each person can learn the secret, starting from person 0 and firstPerson.
//  We use a priority queue to process the nodes in order of their earliest known time, and we update the earliest known time for each neighbor if we find a better time through the current node.
class Solution
{
private:
    vector<int> head;
    vector<int> to;
    vector<int> meet_time;
    vector<int> nxt;
    int edge_cnt;
    inline void add_edge(int u, int v, int t)
    {
        to[edge_cnt] = v;
        meet_time[edge_cnt] = t;
        nxt[edge_cnt] = head[u];
        head[u] = edge_cnt++;
    }
    inline long long pack(long long time, int node)
    {
        return (time << 32) | (long long)node;
    }
    inline long long getTime(long long packed) { return packed >> 32; }
    inline int getNode(long long packed) { return packed & 0xFFFFFFFF; }

public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                              int firstPerson)
    {
        int m = meetings.size();

        head.assign(n, -1);
        to.resize(2 * m);
        meet_time.resize(2 * m);
        nxt.resize(2 * m);
        edge_cnt = 0;

        for (const auto &meet : meetings)
        {
            add_edge(meet[0], meet[1], meet[2]);
            add_edge(meet[1], meet[0], meet[2]);
        }

        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(pack(0LL, 0));
        pq.push(pack(0LL, firstPerson));

        while (!pq.empty())
        {
            long long packed = pq.top();
            pq.pop();

            int u = getNode(packed);
            long long time_known = getTime(packed);

            if (time_known > earliest[u])
            {
                continue;
            }

            for (int e = head[u]; e != -1; e = nxt[e])
            {
                int v = to[e];
                int t = meet_time[e];

                if (t >= time_known && t < earliest[v])
                {
                    earliest[v] = t;
                    pq.push(pack((long long)t, v));
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (earliest[i] != INT_MAX)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};