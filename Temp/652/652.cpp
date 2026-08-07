// Link: https://leetcode.com/problems/find-duplicate-subtrees/description/

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
// Approach: serialize each subtree via postorder string; count occurrences in a map, collect the root of each subtree the first time its serialization count reaches 2.
class Solution {
    unordered_map<string,int> count;
    vector<TreeNode*> res;
    string serialize(TreeNode* node) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);
        count[s]++;
        if (count[s] == 2) res.push_back(node);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
};
