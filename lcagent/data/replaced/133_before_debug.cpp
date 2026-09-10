// Link: https://leetcode.com/problems/clone-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (Node* nb : cur->neighbors) {
                if (!mp.count(nb)) {
                    mp[nb] = new Node(nb->val);
                    q.push(nb);
                }
                // BUG: mp[cur]->neighbors.push_back(mp[nb]);
            }
        }
        return mp[node];
    }
};