// Link: https://leetcode.com/problems/count-non-adjacent-subsets-in-a-rooted-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k^2)  SC: O(n * k)
//  Approach: We can use dynamic programming to solve this problem. We can use a dp array to store the number of valid subsets for each node. We can use a post-order traversal to fill the dp array. For each node, we can calculate the number of valid subsets that include the node and the number of valid subsets that do not include the node. We can use a 2D array to store the number of valid subsets for each node and each remainder when divided by k.
class Solution
{
    static constexpr int MOD = 1'000'000'007;
    struct Active
    {
        uint8_t v[100];
        uint8_t sz = 0;
        inline void clear() { sz = 0; }
        inline void push(uint8_t x)
        {
            v[sz++] = x;
        }
    };

public:
    int countValidSubsets(vector<int> &parent,
                          vector<int> &nums,
                          int k)
    {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i)
        {
            children[parent[i]].push_back(i);
        }
        vector<int> order;
        order.reserve(n);
        {
            vector<int> st{0};
            while (!st.empty())
            {
                int u = st.back();
                st.pop_back();
                order.push_back(u);

                for (int v : children[u])
                {
                    st.push_back(v);
                }
            }
        }
        uint8_t add[100][100];
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                add[i][j] = (i + j) % k;
            }
        }
        vector<int> dp(n * 2 * k);
        vector<Active> active0(n);
        vector<Active> active1(n);
        int next0[100];
        int next1[100];
        bool used0[100];
        bool used1[100];
        for (int idx = n - 1; idx >= 0; --idx)
        {
            int u = order[idx];
            int *u0 = &dp[u * 2 * k];
            int *u1 = u0 + k;
            memset(u0, 0, sizeof(int) * k);
            memset(u1, 0, sizeof(int) * k);
            active0[u].clear();
            active1[u].clear();
            u0[0] = 1;
            active0[u].push(0);
            int r = nums[u] % k;
            u1[r] = 1;
            active1[u].push(r);
            for (int v : children[u])
            {
                int *v0 = &dp[v * 2 * k];
                int *v1 = v0 + k;
                memset(used0, 0, k);
                memset(used1, 0, k);

                Active newA0;
                Active newA1;
                for (int ai = 0; ai < active0[u].sz; ++ai)
                {
                    int i = active0[u].v[ai];
                    int cur0 = u0[i];
                    for (int bj = 0; bj < active0[v].sz; ++bj)
                    {
                        int j = active0[v].v[bj];
                        int ni = add[i][j];
                        long long val =
                            1LL * cur0 * v0[j];
                        if (!used0[ni])
                        {
                            used0[ni] = true;
                            next0[ni] = 0;
                            newA0.push(ni);
                        }
                        next0[ni] =
                            (next0[ni] + val) % MOD;
                    }
                    for (int bj = 0; bj < active1[v].sz; ++bj)
                    {
                        int j = active1[v].v[bj];
                        int ni = add[i][j];
                        long long val =
                            1LL * cur0 * v1[j];
                        if (!used0[ni])
                        {
                            used0[ni] = true;
                            next0[ni] = 0;
                            newA0.push(ni);
                        }
                        next0[ni] =
                            (next0[ni] + val) % MOD;
                    }
                }
                for (int ai = 0; ai < active1[u].sz; ++ai)
                {
                    int i = active1[u].v[ai];
                    int cur1 = u1[i];
                    for (int bj = 0; bj < active0[v].sz; ++bj)
                    {
                        int j = active0[v].v[bj];
                        int ni = add[i][j];
                        long long val =
                            1LL * cur1 * v0[j];
                        if (!used1[ni])
                        {
                            used1[ni] = true;
                            next1[ni] = 0;
                            newA1.push(ni);
                        }
                        next1[ni] =
                            (next1[ni] + val) % MOD;
                    }
                }
                memset(u0, 0, sizeof(int) * k);
                memset(u1, 0, sizeof(int) * k);
                active0[u] = newA0;
                active1[u] = newA1;
                for (int i = 0; i < active0[u].sz; ++i)
                {
                    int r = active0[u].v[i];
                    u0[r] = next0[r];
                }
                for (int i = 0; i < active1[u].sz; ++i)
                {
                    int r = active1[u].v[i];
                    u1[r] = next1[r];
                }
            }
        }
        int *root0 = &dp[0];
        int *root1 = &dp[k];
        return ((root0[0] + root1[0]) % MOD - 1 + MOD) % MOD;
    }
};
