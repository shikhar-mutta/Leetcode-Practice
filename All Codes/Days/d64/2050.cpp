// Link: https://leetcode.com/problems/parallel-courses-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + e)  SC: O(n + e)
//   Approach: Topological sort using Kahn's algorithm. For each course, track the earliest time it can be completed based on its prerequisites. Use a queue to process courses with no remaining prerequisites, updating the earliest completion time for dependent courses as we go. The final answer is the maximum earliest completion time among all courses.
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        static int from[100001]{}, to[100000]{};
        memset(from, 0, sizeof(int) * n);
        static int deg[100000]{};
        memset(deg, 0, sizeof(deg));
        for (const vector<int> &e : relations)
        {
            ++from[e[0] - 1];
            ++deg[e[1] - 1];
        }
        exclusive_scan(from, from + n, from, 0);
        for (const vector<int> &e : relations)
            to[from[e[0] - 1]++] = e[1] - 1;
        for (int i{n}; i > 0; --i)
            from[i] = from[i - 1];
        from[0] = 0;
        queue<int> q{};
        for (int i{0}; i < n; ++i)
        {
            if (deg[i] == 0)
                q.push(i);
        }
        static int srt[100000]{};
        int end{0};
        while (!q.empty())
        {
            const int i{q.front()};
            q.pop();
            srt[end++] = i;
            for (const int j : span<const int>{to + from[i], to + from[i + 1]})
            {
                if (--deg[j] == 0)
                    q.push(j);
            }
        }
        memset(deg, 0, sizeof(deg));
        int res{0};
        for (const int i : span<const int>{srt, srt + n})
        {
            res = max(res, deg[i] += time[i]);
            for (const int j : span<const int>{to + from[i], to + from[i + 1]})
                deg[j] = max(deg[j], deg[i]);
        }
        return res;
    }
};