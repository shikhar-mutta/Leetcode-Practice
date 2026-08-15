// Link: https://leetcode.com/problems/serialize-and-deserialize-bst/description/

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

// TC: O(n)  SC: O(n)
// Approach: preorder serialize (no nulls needed since BST bounds let
// deserialize reconstruct structure); deserialize using min/max bounds
class Codec {
    void ser(TreeNode* node, string& out) {
        if (!node) return;
        out += to_string(node->val) + ",";
        ser(node->left, out);
        ser(node->right, out);
    }

    TreeNode* build(vector<int>& vals, int& idx, int lo, int hi) {
        if (idx >= (int)vals.size() || vals[idx] < lo || vals[idx] > hi) return nullptr;
        TreeNode* node = new TreeNode(vals[idx++]);
        node->left = build(vals, idx, lo, node->val);
        node->right = build(vals, idx, node->val, hi);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string out;
        ser(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        vector<int> vals;
        stringstream ss(data);
        string tok;
        while (getline(ss, tok, ',')) if (!tok.empty()) vals.push_back(stoi(tok));
        int idx = 0;
        return build(vals, idx, INT_MIN, INT_MAX);
    }
};
