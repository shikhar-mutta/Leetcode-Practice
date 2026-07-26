// Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n)
// SC: O(h) recursion depth, h = tree height
// Approach: single post-order pass returning, for each subtree, a pair
// (value, distanceFromStart) where distanceFromStart is -1 if the start
// node isn't in this subtree. If a subtree contains start, "value" is the
// max time to burn everything below it (max of its children's burn times,
// since infection has already reached this node at time 0 within the
// subtree). Otherwise, "value" is just the subtree's height (worst-case
// burn time if the infection arrives here from outside), and once we
// cross the path connecting to whichever side DOES contain start,
// "distanceFromStart" tracks how far this node is from start, letting the
// other (start-free) sibling subtree's burn time be computed as
// distance + that subtree's height.
class Solution {
public:
    pair<int, int> f(TreeNode* node, int start) {
        if (!node)
            return {0, -1};
        auto left = f(node->left, start);
        auto right = f(node->right, start);

        if (node->val == start) {
            int burnTime = max(left.first, right.first);
            return {burnTime, 0};
        } else if (left.second == -1 && right.second == -1) {
            int height = 1 + max(left.first, right.first);
            return {height, -1};
        } else if (left.second != -1) {
            int leftBurn = left.first;
            int myDist = left.second + 1;
            int rightBurn = myDist + right.first;
            return {max(leftBurn, rightBurn), myDist};
        } else {
            int rightBurn = right.first;
            int myDist = right.second + 1;
            int leftBurn = myDist + left.first;
            return {max(leftBurn, rightBurn), myDist};
        }
    }
    int amountOfTime(TreeNode* root, int start) { return f(root, start).first; }
};
