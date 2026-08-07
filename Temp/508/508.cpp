// Link: https://leetcode.com/problems/most-frequent-subtree-sum/description/

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

// TC: O(n)  SC: O(n)
// Approach: postorder computing subtree sums, count frequency of each sum,
// collect sums matching the max frequency
class Solution {
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int sumTree(TreeNode* node) {
        if (!node) return 0;
        int sum = node->val + sumTree(node->left) + sumTree(node->right);
        maxFreq = max(maxFreq, ++freq[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumTree(root);
        vector<int> res;
        for (auto& [sum, cnt] : freq) if (cnt == maxFreq) res.push_back(sum);
        return res;
    }
};
