// Link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

// TC: O(n)  SC: O(n)
// Approach: preorder serialize as "val childCount child1 child2 ..." tokens
// space-separated; deserialize by recursively consuming tokens
class Codec {
    void ser(Node* node, string& out) {
        if (!node) return;
        out += to_string(node->val) + " " + to_string(node->children.size()) + " ";
        for (auto* c : node->children) ser(c, out);
    }

    Node* deser(queue<string>& q) {
        int val = stoi(q.front()); q.pop();
        int cnt = stoi(q.front()); q.pop();
        Node* node = new Node(val);
        for (int i = 0; i < cnt; i++) node->children.push_back(deser(q));
        return node;
    }

public:
    string serialize(Node* root) {
        string out;
        ser(root, out);
        return out;
    }

    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        queue<string> q;
        stringstream ss(data);
        string tok;
        while (ss >> tok) q.push(tok);
        return deser(q);
    }
};
