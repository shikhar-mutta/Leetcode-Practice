// Link: https://leetcode.com/problems/block-placement-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(q log q) SC: O(q)
// Approach: Offline processing of queries in reverse order. Maintain a sorted list of obstacles and a BIT to track the maximum gap between consecutive obstacles. Use DSU to manage active/inactive obstacles and efficiently answer placement queries.
// 1. Collect all obstacle positions and sort them.
// 2. Initialize a DSU to manage active/inactive obstacles.
// 3. Use a BIT to track the maximum gap between consecutive obstacles.
// 4. Process queries in reverse order, updating the BIT and DSU as obstacles are removed and answering placement queries based on the current state of obstacles and gaps.
// 5. Reverse the results to match the original query order before returning.
// 6. The DSU is used to efficiently find the largest active obstacle index for placement queries, while the BIT allows for quick maximum gap queries.
// 7. The overall complexity is dominated by the sorting of obstacles and the processing of queries, leading to O(q log q) time complexity.
class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int val)
    {
        i += 1; // Translate to 1-based indexing for the BIT
        while (i <= n)
        {
            bit[i] = max(bit[i], val);
            i += (i & -i);
        }
    }

    int query(int i)
    {
        i += 1; // Translate to 1-based indexing for the BIT
        int ret = 0;
        while (i > 0)
        {
            ret = max(ret, bit[i]);
            i -= (i & -i);
        }
        return ret;
    }
};

class Solution
{
    vector<int> parent;

    // Path-compressed iterative DSU find operation
    int find(int i)
    {
        int root = i;
        while (parent[root] != root)
        {
            root = parent[root];
        }
        int curr = i;
        while (curr != root)
        {
            int nxt = parent[curr];
            parent[curr] = root;
            curr = nxt;
        }
        return root;
    }

public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {
        // 1. Collect all obstacle positions to build a sorted list of potential
        // obstacles
        vector<int> sl;
        for (const auto &q : queries)
        {
            if (q[0] == 1)
            {
                sl.push_back(q[1]);
            }
        }
        sort(sl.begin(), sl.end());
        sl.erase(unique(sl.begin(), sl.end()), sl.end());

        int m = sl.size();

        // 2. Initialize the DSU (index m represents the inactive sentinel
        // state)
        parent.resize(m + 1);
        for (int i = 0; i <= m; ++i)
        {
            parent[i] = i;
        }

        // 3. Pointer arrays to act as a doubly linked list
        vector<int> prev_active(m);
        vector<int> next_active(m);
        for (int i = 0; i < m; ++i)
        {
            prev_active[i] = i - 1;
            next_active[i] = i + 1;
        }

        // 4. Initialize the BIT with all obstacles present initially
        BIT bit(m);
        for (int i = 0; i < m; ++i)
        {
            int gap = sl[i] - (i > 0 ? sl[i - 1] : 0);
            bit.update(i, gap);
        }

        vector<bool> result;

        // 5. Process queries in reverse order
        for (auto it = queries.rbegin(); it != queries.rend(); ++it)
        {
            const auto &q = *it;
            if (q[0] == 1)
            {
                int x = q[1];
                int idx = lower_bound(sl.begin(), sl.end(), x) - sl.begin();

                int p = prev_active[idx];
                int n = next_active[idx];

                // Merge intervals
                if (n < m)
                {
                    int new_gap = sl[n] - (p >= 0 ? sl[p] : 0);
                    bit.update(n, new_gap);
                    prev_active[n] = p;
                }
                if (p >= 0)
                {
                    next_active[p] = n;
                }

                // Mark index as inactive
                if (idx > 0)
                {
                    parent[idx] = idx - 1;
                }
                else
                {
                    parent[0] = m; // Point to sentinel
                }
            }
            else
            {
                int x = q[1];
                int sz = q[2];

                int idx = lower_bound(sl.begin(), sl.end(), x) - sl.begin();
                int start_idx = idx - 1;

                // Find the largest active obstacle index <= start_idx
                int active_idx = -1;
                if (start_idx >= 0)
                {
                    active_idx = find(start_idx);
                    if (active_idx == m)
                    {
                        active_idx = -1;
                    }
                }

                int prev_x = (active_idx >= 0) ? sl[active_idx] : 0;

                bool ans = false;
                if (x - prev_x >= sz)
                {
                    ans = true;
                }
                else if (active_idx >= 0)
                {
                    if (bit.query(active_idx) >= sz)
                    {
                        ans = true;
                    }
                }
                result.push_back(ans);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};