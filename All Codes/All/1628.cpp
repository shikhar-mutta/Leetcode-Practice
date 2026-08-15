// Link: https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    virtual ~Node() {};
    virtual int evaluate() const = 0;
};

class NumNode : public Node {
public:
    int val;
    NumNode(int v) : val(v) {}
    int evaluate() const override { return val; }
};

class OpNode : public Node {
public:
    char op;
    Node* left;
    Node* right;
    OpNode(char o, Node* l, Node* r) : op(o), left(l), right(r) {}
    int evaluate() const override {
        int a = left->evaluate();
        int b = right->evaluate();
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
};

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node*> st;
        for (auto& tok : postfix) {
            if (tok.size() == 1 && !isdigit(tok[0])) {
                Node* right = st.back(); st.pop_back();
                Node* left = st.back(); st.pop_back();
                st.push_back(new OpNode(tok[0], left, right));
            } else {
                st.push_back(new NumNode(stoi(tok)));
            }
        }
        return st.back();
    }
};

class Solution {
public:
    Node* buildTreeFromPostfix(vector<string>& postfix) {
        TreeBuilder tb;
        return tb.buildTree(postfix);
    }
};
