// Link: https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/

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
    vector<int> sizes;

    // returns {size, height} if perfect, else {-1,-1}; also collects sizes for all perfect subtrees
    pair<int,int> check(TreeNode* node) {
        if (!node) return {0, 0};
        auto L = check(node->left);
        auto R = check(node->right);
        if (L.first == -1 || R.first == -1 || L.second != R.second) {
            return {-1, -1};
        }
        int size = L.first + R.first + 1;
        int height = L.second + 1;
        sizes.push_back(size);
        return {size, height};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        sizes.clear();
        check(root);
        sort(sizes.rbegin(), sizes.rend());
        if (k > (int)sizes.size()) return -1;
        return sizes[k-1];
    }
};
