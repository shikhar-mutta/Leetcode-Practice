// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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
    // TC: O(4^n / sqrt(n)) - The number of unique BSTs that can be formed with n nodes is given by the nth Catalan number, which is approximately 4^n / (n^(3/2) * sqrt(pi)). Therefore, the time complexity of generating all unique BSTs is O(4^n / sqrt(n)).
    // SC: O(4^n / sqrt(n)) - The space complexity is also O(4^n / sqrt(n)) because we need to store all the unique BSTs that can be formed with n nodes. Each unique BST can have up to n nodes, and there are approximately 4^n / (n^(3/2) * sqrt(pi)) unique BSTs, so the total space required is O(4^n / sqrt(n)).
    // Approach:
    //   1. We define a recursive function build that takes two parameters lo and hi, representing the range of values that can be used to construct the BST.
    //   2. If lo is greater than hi, we return a vector containing a single nullptr, representing an empty subtree.
    //   3. We initialize an empty vector result to store the unique BSTs that can be formed with the values in the range [lo, hi].
    //   4. We iterate through all values i from lo to hi, treating each value as the root of the BST. For each value of i, we recursively generate all unique left subtrees using the values in the range [lo, i-1] and all unique right subtrees using the values in the range [i+1, hi].
    //   5. We combine each unique left subtree with each unique right subtree to form a new BST with root i, and we add this new BST to the result vector.
    //   6. Finally, we return the result vector containing all unique BSTs that can be formed with the values in the range [lo, hi].
    vector<TreeNode *> generateTrees(int n)
    {
        function<vector<TreeNode *>(int, int)> build = [&](int lo, int hi) -> vector<TreeNode *>
        {
            if (lo > hi)
                return {nullptr};
            vector<TreeNode *> result;
            for (int i = lo; i <= hi; i++)
            {
                auto lefts = build(lo, i - 1);
                auto rights = build(i + 1, hi);
                for (auto l : lefts)
                    for (auto r : rights)
                        result.push_back(new TreeNode(i, l, r));
            }
            return result;
        };
        if (n == 0)
            return {};
        return build(1, n);
    }
};
