// Link: https://leetcode.com/problems/linked-list-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;
        if (node->val != head->val) return false;
        return dfs(head->next, node->left) || dfs(head->next, node->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        if (dfs(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
