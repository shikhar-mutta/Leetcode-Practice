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

// TC: O(n log n)
// SC: O(w) where w = widest level
// Approach: BFS level by level. For each level, pair each value with its
// target sorted position, then count the minimum adjacent swaps needed to
// realize that permutation by decomposing it into cycles: a cycle of
// length c needs c - 1 swaps. Sum this over every level.
class Solution {
public:
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ttl_swaps = 0;
        while (!q.empty()) {
            int n = q.size();
            int t[n];
            pair<int, int> s[n];
            bool visited[n];
            memset(visited, false, n);
            for (int i = 0; i < n; i++) {
                TreeNode* r = q.front();
                q.pop();
                t[i] = r->val;
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            // 1.
            for (int i = 0; i < n; i++)
                s[i] = make_pair(t[i], i);
            sort(s, s + n);
            for (int i = 0; i < n; i++) {
                // 2.
                if (visited[i] || s[i].second == i)
                    continue;
                int c_len = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = s[j].second;
                    c_len++;
                }
                // 3.
                if (c_len > 0)
                    ttl_swaps += c_len - 1;
            }
        }
        return ttl_swaps;
    }
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;
        return bfs(root);
    }
};
