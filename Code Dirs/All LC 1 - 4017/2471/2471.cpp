// Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

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
    int minSwaps(vector<int> arr) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return arr[a] < arr[b]; });

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || idx[i] == i) continue;
            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = idx[j];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        int total = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            total += minSwaps(level);
        }
        return total;
    }
};
