// Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        function<void(TreeNode*, TreeNode*)> build = [&](TreeNode* node, TreeNode* parent) {
            if (!node) return;
            if (parent) {
                adj[node->val].push_back(parent->val);
                adj[parent->val].push_back(node->val);
            }
            build(node->left, node);
            build(node->right, node);
        };
        build(root, nullptr);

        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int minutes = -1;
        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            for (int i = 0; i < sz; i++) {
                int cur = q.front(); q.pop();
                for (int nxt : adj[cur]) {
                    if (!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
        }
        return minutes;
    }
};
