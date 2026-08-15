// Link: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n) SC: O(n)
// Approach: convert tree to an undirected graph (each node linked to parent and children), find the node with value k, then BFS from it; the first leaf encountered (node with no children in original tree) is the closest.
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaves;
        TreeNode* start = nullptr;
        function<void(TreeNode*, TreeNode*)> build = [&](TreeNode* node, TreeNode* parent) {
            if (!node) return;
            if (node->val == k) start = node;
            if (!node->left && !node->right) leaves.insert(node);
            if (parent) {
                graph[node].push_back(parent);
                graph[parent].push_back(node);
            }
            build(node->left, node);
            build(node->right, node);
        };
        build(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (leaves.count(node)) return node->val;
            for (auto* nb : graph[node]) {
                if (!visited.count(nb)) {
                    visited.insert(nb);
                    q.push(nb);
                }
            }
        }
        return -1;
    }
};
