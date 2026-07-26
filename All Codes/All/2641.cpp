// Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

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

// TC: O(n)
// SC: O(n) for the BFS queue/level buffers
// Approach: level-order BFS. For each level, first sum ALL of its nodes'
// children values (nextLevelSum = the cousins-sum every child on the next
// level shares). Then for each node, its own two children's new values are
// nextLevelSum minus their own sibling-pair sum (excludes only its direct
// sibling, giving exactly the sum of same-level nodes with a different parent).
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;   // root has no cousins
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            // first, compute the total value of the next level
            long long nextLevelSum = 0;
            vector<TreeNode*> curLevel;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                curLevel.push_back(node);
                if (node->left)  nextLevelSum += node->left->val;
                if (node->right) nextLevelSum += node->right->val;
            }

            // assign each child's new value: nextLevelSum minus its sibling group sum
            for (TreeNode* node : curLevel) {
                long long siblingSum = 0;
                if (node->left)  siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left)  node->left->val  = nextLevelSum - siblingSum;
                if (node->right) node->right->val = nextLevelSum - siblingSum;
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
