// Link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size)
{
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n), SC: O(h) where h is the height of the tree
//  Approach:
//   1. We perform a depth-first search (DFS) traversal of the cloned binary tree. We start from the root of the cloned tree and recursively explore its left and right subtrees.
//   2. At each node, we check if the value of the current node in the cloned tree matches the value of the target node. If it does, we store a pointer to that node in the ans variable.
//   3. We continue the traversal until we have visited all nodes in the cloned tree. The recursion will eventually return to the root of the cloned tree, and we return the pointer to the corresponding node in the cloned tree that matches the target node from the original tree.
class Solution
{
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    TreeNode *ans;
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target)
    {
        if (cloned == NULL)
            return cloned;
        if (cloned->val == target->val)
            ans = cloned;
        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);
        return ans;
    }
};
