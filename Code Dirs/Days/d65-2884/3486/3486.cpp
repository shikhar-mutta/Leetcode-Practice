// Link: https://leetcode.com/problems/longest-special-path-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n). SC: O(n).
// Approach: We can use DFS to traverse the tree and keep track of the last depth we saw each value. We also keep track of the path distance at each depth. When we visit a node, we check if we have seen its value before and update the best length and number of nodes accordingly.
class Solution
{
private:
    vector<vector<pair<int, int>>> adj;
    vector<int> nums;
    vector<int> lastDepth;
    vector<long long> pathDist;
    int left = 0, left2 = 0;
    long long bestLen = 0;
    int bestNodes = 1;

    void dfs(int u, int parent, int depth, long long dist)
    {
        int v = nums[u];
        int oldLast = lastDepth[v];
        int oldLeft = left, oldLeft2 = left2;

        if (oldLast > left2)
        {
            left = left2;
            left2 = oldLast;
        }
        else if (oldLast > left)
        {
            left = oldLast;
        }

        lastDepth[v] = depth;
        pathDist[depth] = dist;

        long long curLen = dist - pathDist[left + 1];
        int curNodes = depth - left;
        if (curLen > bestLen || (curLen == bestLen && curNodes < bestNodes))
        {
            bestLen = curLen;
            bestNodes = curNodes;
        }

        for (auto &[nxt, w] : adj[u])
        {
            if (nxt != parent)
                dfs(nxt, u, depth + 1, dist + w);
        }

        lastDepth[v] = oldLast;
        left = oldLeft;
        left2 = oldLeft2;
    }

public:
    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums_)
    {
        int n = nums_.size();
        nums = nums_;
        adj.assign(n, {});
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        lastDepth.assign(maxVal + 1, 0);
        pathDist.assign(n + 1, 0);
        dfs(0, -1, 1, 0);
        return {(int)bestLen, bestNodes};
    }
};
