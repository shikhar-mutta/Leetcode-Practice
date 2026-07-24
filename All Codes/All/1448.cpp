// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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

class Solution
{
public:
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }

private:
    int dfs(TreeNode *root, int maxsofar)
    {
        if (!root)
            return 0;
        int count = 0;

        if (root->val >= maxsofar)
            count = 1; // if the first node is greater than max (it will be) so
                       // we add 1
        // updating max for the children nodes
        maxsofar = max(maxsofar, root->val);
        count += dfs(root->left, maxsofar);
        count += dfs(root->right, maxsofar);

        return count;
    }
};

static const bool __boost = []()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();

// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x30000000;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *operator new(size_t size)
{
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void * /*unused*/, unsigned long /*unused*/) noexcept {}
void operator delete(void * /*unused*/) noexcept {}
void operator delete[](void * /*unused*/) noexcept {}
void operator delete[](void * /*unused*/, size_t /*unused*/) noexcept {}