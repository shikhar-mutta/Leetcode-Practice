// Link: https://leetcode.com/problems/all-possible-full-binary-trees/description/

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
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.count(n)) return memo[n];
        vector<TreeNode*> res;
        if (n % 2 == 0) return res;
        if (n == 1) { res.push_back(new TreeNode(0)); memo[n] = res; return res; }
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            auto leftTrees = allPossibleFBT(left);
            auto rightTrees = allPossibleFBT(right);
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    res.push_back(new TreeNode(0, l, r));
                }
            }
        }
        memo[n] = res;
        return res;
    }
};
