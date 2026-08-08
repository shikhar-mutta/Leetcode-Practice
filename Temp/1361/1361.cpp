// Link: https://leetcode.com/problems/validate-binary-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1 && ++indegree[leftChild[i]] > 1) return false;
            if (rightChild[i] != -1 && ++indegree[rightChild[i]] > 1) return false;
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;

        int visited = 0;
        unordered_set<int> seen;
        queue<int> q;
        q.push(root);
        seen.insert(root);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            for (int v : {leftChild[u], rightChild[u]}) {
                if (v != -1) {
                    if (seen.count(v)) return false;
                    seen.insert(v);
                    q.push(v);
                }
            }
        }
        return visited == n;
    }
};
