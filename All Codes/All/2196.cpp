// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

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

// TC: O(n), n = descriptions.size()
// SC: O(1) extra beyond the fixed-size static arena (bounded by the 1e5
// value-range constraint, not by n)
// Approach: since node values are bounded (<=1e5), use them directly as
// indices into a preallocated TreeNode arena instead of a hash map, keyed
// by a "generation" counter so the arena can be reused across calls without
// re-zeroing it each time. One pass wires up every parent->child pointer
// (lazily initializing each node's slot on first sight) and marks children;
// a second pass finds the one node from descriptions that was never marked
// as a child - that's the root.
class Solution {
    static TreeNode arena[100001];
    static int gen[100001];
    static int isChild[100001];
    static int currentGen;

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ++currentGen;

        // Pin pointer to the base array vector to bypass heap chasing
        // descriptions is contiguous arrays of 3 elements under the hood
        const int n = descriptions.size();

        int potential_root_sum = 0;

        // Loop unrolling hints for the GCC compiler
        #pragma unroll
        for (int i = 0; i < n; ++i) {
            const auto& desc = descriptions[i];
            const int parent = desc[0];
            const int child  = desc[1];
            const int isLeft = desc[2];

            // Branchless / direct layout mapping
            if (gen[parent] != currentGen) {
                arena[parent].val = parent;
                arena[parent].left = arena[parent].right = nullptr;
                gen[parent] = currentGen;
                isChild[parent] = 0;
            }
            if (gen[child] != currentGen) {
                arena[child].val = child;
                arena[child].left = arena[child].right = nullptr;
                gen[child] = currentGen;
                isChild[child] = 0;
            }

            // Assign pointers without nested logical operations
            if (isLeft) {
                arena[parent].left = &arena[child];
            } else {
                arena[parent].right = &arena[child];
            }

            isChild[child] = currentGen;
        }

        // Final super-fast single scan using vector memory limits
        for (int i = 0; i < n; ++i) {
            const int parent = descriptions[i][0];
            if (isChild[parent] != currentGen) {
                return &arena[parent];
            }
        }

        return nullptr;
    }
};

// Global segment layout initialization
TreeNode Solution::arena[100001];
int Solution::gen[100001] = {0};
int Solution::isChild[100001] = {0};
int Solution::currentGen = 0;
