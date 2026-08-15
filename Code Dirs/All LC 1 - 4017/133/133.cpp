// Link: https://leetcode.com/problems/clone-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() { val = 0; neighbors = vector<Node*>(); }
    Node(int _val) { val = _val; neighbors = vector<Node*>(); }
    Node(int _val, vector<Node*> _neighbors) { val = _val; neighbors = _neighbors; }
};

// TC: O(n)  SC: O(n)
// Approach: DFS with a hash map from original node to its clone, cloning neighbors recursively before linking
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> memo;
        function<Node*(Node*)> dfs = [&](Node* orig) -> Node* {
            if (memo.count(orig)) return memo[orig];
            Node* copy = new Node(orig->val);
            memo[orig] = copy;
            for (auto nb : orig->neighbors) copy->neighbors.push_back(dfs(nb));
            return copy;
        };
        return dfs(node);
    }
};
