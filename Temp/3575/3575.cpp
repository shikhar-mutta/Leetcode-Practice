// Link: https://leetcode.com/problems/maximum-good-subtree-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^10): For each node, we can have at most 2^10 different configurations of digits (since there are 10 digits). For each configuration, we can calculate the maximum score by iterating through the children of the node and combining their scores.
// SC: O(n * 2^10): For storing the maximum score for each configuration
// Approach: The problem can be solved by using a depth-first search (DFS) approach. We can start from the root node and for each node, we can calculate the maximum score for each configuration of digits. We can use a bitmask to represent the configuration of digits and for each child of the node, we can combine their scores with the current node's score. We can use a struct to store the maximum score for each configuration and return the maximum score for the root node.
class Solution
{
public:
    // A standard C++ struct wrapped in an array forces a strict underlying
    // layout
    struct AlignmentWrapper
    {
        long long arr[1024];
    };

    pair<long long, AlignmentWrapper> dfs(int u, const vector<int> &vals,
                                          const vector<vector<int>> &adj)
    {
        long long current_node_subtree_sum = 0;
        AlignmentWrapper local_dp;

        // Fast, block-level initialization using standard library functions
        std::fill(std::begin(local_dp.arr), std::end(local_dp.arr), -1);

        // 1. Calculate current node mask
        int u_mask = 0;
        bool self_valid = true;
        for (int x = vals[u]; x > 0; x /= 10)
        {
            int digit = x % 10;
            if (u_mask & (1 << digit))
            {
                self_valid = false;
                break;
            }
            u_mask |= (1 << digit);
        }

        local_dp.arr[0] = 0; // The empty set configuration is always valid
        if (self_valid)
        {
            local_dp.arr[u_mask] = vals[u];
        }

        // 2. Process children sequentially
        for (int v : adj[u])
        {
            // Move semantics safely transfer the child's array upward without
            // deep copying
            auto [child_sum, child_dp] = dfs(v, vals, adj);
            current_node_subtree_sum =
                (current_node_subtree_sum + child_sum) % 1'000'000'007;

            // Snapshot the current parent state to prevent double-counting
            // configurations
            AlignmentWrapper next_buffer = local_dp;

            // Worst-Case Optimization: Flat cache-friendly arrays streaming at
            // hardware speed
            for (int i = 1023; i >= 0; --i)
            {
                if (local_dp.arr[i] == -1)
                    continue;

                int comp = 1023 ^ i;
                for (int j = comp; j > 0; j = (j - 1) & comp)
                {
                    if (child_dp.arr[j] != -1)
                    {
                        next_buffer.arr[i | j] =
                            max(next_buffer.arr[i | j],
                                local_dp.arr[i] + child_dp.arr[j]);
                    }
                }
            }
            local_dp = next_buffer; // Standard structure copy assignment
        }

        // 3. Find the best overall sum configuration for this root
        long long max_good = 0;
        for (int i = 0; i < 1024; ++i)
        {
            max_good = max(max_good, local_dp.arr[i]);
        }

        long long total_sum =
            (current_node_subtree_sum + max_good) % 1'000'000'007;
        return {total_sum,
                local_dp}; // Bypasses copy mechanics entirely in C++20 via NRVO
    }

    int goodSubtreeSum(vector<int> &vals, vector<int> &par)
    {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (int u = 1; u < n; ++u)
        {
            adj[par[u]].push_back(u);
        }

        return dfs(0, vals, adj).first;
    }
};