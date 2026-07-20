// Link: https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m + n * k) where n is number of nodes, m is number of edges and k is the maximum number of neighbors to consider for each node.
// SC: O(n + m) where n is number of nodes and m is number of edges. We are using adjacency list representation of graph which takes O(n + m) space.
// Approach:
//  1. We will use adjacency list representation of graph to store the edges.
//  2. For each node, we will iterate over its neighbors and store their values in a buffer array.
//  3. We will then sort the buffer array in descending order and take the first k elements to calculate the star sum for that node.
//  4. We will keep track of the maximum star sum encountered so far and return it at the end.
//  Note: We are using nth_element to partially sort the buffer array which takes O(n) time on average. This is more efficient than sorting the entire array which takes O(n log n) time.

#pragma GCC optimize("Ofast,unroll-loops")
// Ofast -> -03
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// avx2 -> advanced vector(parallelization of registers (new registers support 256 bits which can handle more than one int addition/substraction/computation) ) extension 2
// bmi -> bitmask optimization

#include <vector>
#include <algorithm>

static const auto fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

int head[100005];
int nxt[200005];
int to_val[200005];
int e_idx;

int neighbor_buffer[100005];

class Solution
{

    // inline replaces the actual function call with code, saving time overhead of creating new stack frame.
    // head points to latest added edge for a noude u.
    // nxt points to next edge for a particular edge.
    // to_val stores the next edge node value.
    // Here we are maintaining a linked list of edges from a particular node, we add new edge from head.
    inline void add_edge(int u, int v_val)
    {
        if (v_val <= 0)
            return; // optimization : if negative weight cannot increase the result so prune.
        to_val[e_idx] = v_val;
        nxt[e_idx] = head[u];
        head[u] = e_idx++;
    }

public:
    int maxStarSum(std::vector<int> &vals, std::vector<std::vector<int>> &edges, int k)
    {
        int n = vals.size();
        e_idx = 0;
        for (int i = 0; i < n; i++)
            head[i] = -1;

        for (const auto &e : edges)
        {
            // adding both edges for undirected graph
            add_edge(e[0], vals[e[1]]);
            add_edge(e[1], vals[e[0]]);
        }

        long long global_max = -2e18;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            // iterating over linked list
            for (int e = head[i]; e != -1; e = nxt[e])
            {
                neighbor_buffer[count++] = to_val[e];
            }
            long long current_sum = vals[i];

            if (count > 0)
            {
                int take = std::min(count, k);
                // from nums[0] to nums[take] to nums[end]
                // take is pivot so all thing bofer will be greater and after will be smaller.
                std::nth_element(neighbor_buffer, neighbor_buffer + take, neighbor_buffer + count, std::greater<int>());

                for (int j = 0; j < take; j++)
                {
                    current_sum += neighbor_buffer[j];
                }
            }
            if (current_sum > global_max)
                global_max = current_sum;
        }
        return (int)global_max;
    }
};
