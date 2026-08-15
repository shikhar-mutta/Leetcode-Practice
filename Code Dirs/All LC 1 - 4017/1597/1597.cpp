// Link: https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char val;
    Node *left;
    Node *right;
    Node() {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int precedence(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }

    void applyOp(stack<Node*>& nodes, stack<char>& ops) {
        char op = ops.top(); ops.pop();
        Node* right = nodes.top(); nodes.pop();
        Node* left = nodes.top(); nodes.pop();
        nodes.push(new Node(op, left, right));
    }

    Node* expTree(string s) {
        stack<Node*> nodes;
        stack<char> ops;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                nodes.push(new Node(c));
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (ops.top() != '(') applyOp(nodes, ops);
                ops.pop();
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!ops.empty() && ops.top() != '(' && precedence(ops.top()) >= precedence(c)) applyOp(nodes, ops);
                ops.push(c);
            }
        }
        while (!ops.empty()) applyOp(nodes, ops);
        return nodes.top();
    }
};
