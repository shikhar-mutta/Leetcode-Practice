// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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

// TC: O(Catalan(n) * n)  SC: O(Catalan(n) * n)
// Approach: recursive divide-conquer build(lo,hi) trying each value as root, combining left×right subtree choices
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
private:
    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};
        vector<TreeNode*> res;
        for (int root = lo; root <= hi; root++) {
            auto lefts = build(lo, root - 1);
            auto rights = build(root + 1, hi);
            for (auto l : lefts) {
                for (auto r : rights) {
                    res.push_back(new TreeNode(root, l, r));
                }
            }
        }
        return res;
    }
};
