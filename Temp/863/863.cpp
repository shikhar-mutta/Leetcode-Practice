// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        function<void(TreeNode*, TreeNode*)> buildParents = [&](TreeNode* node, TreeNode* par) {
            if (!node) return;
            parent[node] = par;
            buildParents(node->left, node);
            buildParents(node->right, node);
        };
        buildParents(root, nullptr);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        while (!q.empty()) {
            if (dist == k) {
                vector<int> res;
                while (!q.empty()) { res.push_back(q.front()->val); q.pop(); }
                return res;
            }
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                for (TreeNode* nb : {node->left, node->right, parent[node]}) {
                    if (nb && !visited.count(nb)) {
                        visited.insert(nb);
                        q.push(nb);
                    }
                }
            }
            dist++;
        }
        return {};
    }
};
