// Link: https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void count(Node* node, unordered_map<char,int>& freq) {
        if (!node) return;
        if (isalpha(node->val)) freq[node->val]++;
        count(node->left, freq);
        count(node->right, freq);
    }

    bool checkEquivalence(Node* root1, Node* root2) {
        unordered_map<char,int> f1, f2;
        count(root1, f1);
        count(root2, f2);
        return f1 == f2;
    }
};
