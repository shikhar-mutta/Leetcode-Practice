// Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//    Approach:
//      1. We can use a hash map to store the adjacent pairs of each number.
//      2. We can then find one of the end nodes (the node with only one neighbor) and use it to reconstruct the original array by traversing through the adjacent pairs.
//   Note: We can use a struct to represent each node and its neighbors, and we can use the hash map to store the nodes and their neighbors. We can also use a vector to store the original array.
class Solution
{
public:
    std::vector<int>
    restoreArray(const std::vector<std::vector<int>> &adjacent_pairs)
    {
        std::unordered_map<int, ListNode> list_nodes;

        for (const auto &pair : adjacent_pairs)
        {
            const int node1_val = pair[0];
            const int node2_val = pair[1];
            const auto [iter1, inserted1] = list_nodes.try_emplace(node1_val);
            const auto [iter2, inserted2] = list_nodes.try_emplace(node2_val);
            ListNode &node1 = iter1->second;
            ListNode &node2 = iter2->second;

            if (node1.neighbor1 == INVALID_NODE_VAL)
                node1.neighbor1 = node2_val;
            else
                node1.neighbor2 = node2_val;

            if (node2.neighbor1 == INVALID_NODE_VAL)
                node2.neighbor1 = node1_val;
            else
                node2.neighbor2 = node1_val;
        }

        // finding one of the end nodes
        auto first_node_iter = list_nodes.cbegin();
        while (first_node_iter->second.neighbor2 != INVALID_NODE_VAL)
            ++first_node_iter;

        // constructing the original vector
        auto prev_node_iter = list_nodes.cend();
        auto curr_node_iter = first_node_iter;
        std::vector<int> original(adjacent_pairs.size() + 1);
        size_t next_idx = 0;
        original[next_idx++] = curr_node_iter->first;
        while (next_idx < original.size())
        {
            if (prev_node_iter == list_nodes.cend() ||
                curr_node_iter->second.neighbor1 != prev_node_iter->first)
            {
                prev_node_iter = curr_node_iter;
                curr_node_iter =
                    list_nodes.find(curr_node_iter->second.neighbor1);
            }
            else
            {
                prev_node_iter = curr_node_iter;
                curr_node_iter =
                    list_nodes.find(curr_node_iter->second.neighbor2);
            }
            original[next_idx++] = curr_node_iter->first;
        }
        return original;
    }

private:
    static constexpr int INVALID_NODE_VAL = std::numeric_limits<int>::min();
    struct ListNode
    {
        int neighbor1 = INVALID_NODE_VAL;
        int neighbor2 = INVALID_NODE_VAL;
    };
};