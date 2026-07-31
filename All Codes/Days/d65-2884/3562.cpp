// Link: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * budget^2)
// SC: O(n * budget)
// Approach: DP on tree
//  dp[node][bossBought][buy][budget] = max profit we can get from the subtree rooted at node, given that the boss of this node is bought or not, we buy this node or not, and we have budget left  .

const int N = 161, N4 = 161 * 4;
int profit[N][2];
vector<int> children[N];
int dp[N][2][2][N];
bitset<N4> vis;
class Solution
{
public:
    int n;
    void buildTree(vector<vector<int>> &hierarchy)
    {
        for (int i = 0; i < n; i++)
            children[i].clear();

        for (auto &e : hierarchy)
            children[e[0] - 1].push_back(e[1] - 1);
    }
    void dfs(int node, bool bossBought, bool buy, int budget,
             vector<int> &present)
    {
        int state = (node << 2) | (bossBought << 1) | buy;
        if (vis[state])
            return;
        vis[state] = 1;
        int *cache = dp[node][bossBought][buy];
        fill(cache, cache + budget + 1, INT_MIN);
        int cost = 0;
        if (buy)
        {
            if (bossBought)
                cost = present[node] / 2;
            else
                cost = present[node];
        }
        if (cost <= budget)
        {
            cache[cost] = buy ? profit[node][bossBought] : 0;
        }
        int cur[N];
        int merged[N];
        memcpy(cur, cache, sizeof(int) * (budget + 1));
        for (int child : children[node])
        {
            dfs(child, buy, true, budget, present);
            dfs(child, false, false, budget, present);
            int *take = dp[child][buy][1];
            int *skip = dp[child][0][0];
            fill(merged, merged + budget + 1, INT_MIN);
            for (int b = 0; b <= budget; b++)
            {
                if (cur[b] == INT_MIN)
                    continue;
                for (int x = 0; b + x <= budget; x++)
                {
                    int best = max(take[x], skip[x]);
                    if (best == INT_MIN)
                        continue;
                    merged[b + x] = max(merged[b + x], cur[b] + best);
                }
            }
            memcpy(cur, merged, sizeof(int) * (budget + 1));
        }
        memcpy(cache, cur, sizeof(int) * (budget + 1));
    }
    int maxProfit(int n, vector<int> &present, vector<int> &future,
                  vector<vector<int>> &hierarchy, int budget)
    {
        this->n = n;
        vis.reset();
        for (int i = 0; i < n; i++)
        {
            profit[i][0] = future[i] - present[i];
            profit[i][1] = future[i] - present[i] / 2;
        }
        buildTree(hierarchy);
        dfs(0, false, false, budget, present);
        dfs(0, false, true, budget, present);
        int ans = 0;
        for (int b = 0; b <= budget; b++)
        {
            ans = max(ans, dp[0][0][0][b]);
            ans = max(ans, dp[0][0][1][b]);
        }
        return ans;
    }
};
