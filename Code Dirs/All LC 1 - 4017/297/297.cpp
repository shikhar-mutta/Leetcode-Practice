// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

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

// TC: O(n) serialize/deserialize  SC: O(n)
// Approach: preorder traversal with "null" markers, comma-separated
class Codec {
    void ser(TreeNode* node, string& out) {
        if (!node) { out += "null,"; return; }
        out += to_string(node->val) + ",";
        ser(node->left, out);
        ser(node->right, out);
    }

    TreeNode* deser(queue<string>& q) {
        string tok = q.front(); q.pop();
        if (tok == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(tok));
        node->left = deser(q);
        node->right = deser(q);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string out;
        ser(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string tok;
        while (getline(ss, tok, ',')) if (!tok.empty()) q.push(tok);
        return deser(q);
    }
};
