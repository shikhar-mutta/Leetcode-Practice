// Link: https://leetcode.com/problems/construct-binary-tree-from-string/description/

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
// Approach: recursive-descent parse; read a (possibly negative) number,
// then optionally a parenthesized left subtree, then optionally a
// parenthesized right subtree
class Solution {
    int pos = 0;

    int readNum(const string& s) {
        int start = pos;
        if (s[pos] == '-') pos++;
        while (pos < (int)s.size() && isdigit(s[pos])) pos++;
        return stoi(s.substr(start, pos - start));
    }

    TreeNode* parse(const string& s) {
        int val = readNum(s);
        TreeNode* node = new TreeNode(val);
        if (pos < (int)s.size() && s[pos] == '(') {
            pos++; // consume '('
            node->left = parse(s);
            pos++; // consume ')'
        }
        if (pos < (int)s.size() && s[pos] == '(') {
            pos++;
            node->right = parse(s);
            pos++;
        }
        return node;
    }

public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        pos = 0;
        return parse(s);
    }
};
