// Link: https://leetcode.com/problems/count-complete-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        // Heights walking only the left / right spines.
        int lh = 0, rh = 0;
        for (TreeNode *p = root; p; p = p->left)
            lh++;
        for (TreeNode *p = root; p; p = p->right)
            rh++;

        // Perfect subtree → 2^h - 1 nodes, no recursion needed.
        if (lh == rh)
            return (1 << lh) - 1;

        // Otherwise the last level is partial: binary-search which leaves exist.
        int h = lh - 1; // depth of the last (incomplete) level

        // Last incomplete level has index range [0, 2^h - 1]. Binary search for the last present node.
        int lo = 0, hi = (1 << h) - 1; // index range of last-level slots

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (exists(root, mid, h))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        // Nodes above last level: 2^h - 1; plus `lo` present last-level nodes.
        return (1 << h) - 1 + lo;
    }

private:
    // Does the last-level slot `idx` (0-based) exist? Walk the path encoded by idx's bits.
    bool exists(TreeNode *root, int idx, int h)
    {
        TreeNode *node = root; // Start at root and walk down to the last level.

        // The bits of idx represent the path to take: 0 → left, 1 → right.
        // traverse bits from the most significant to the least significant, ignoring the leading 1 bit
        for (int bit = h - 1; bit >= 0 && node; --bit)
            node = (idx & (1 << bit)) ? node->right : node->left;
        //        000
        //    000      001
        // 000 001  010   011
        return node != nullptr;
    }
};
