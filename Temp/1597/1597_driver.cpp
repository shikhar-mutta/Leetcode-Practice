#include <bits/stdc++.h>
using namespace std;
#include "1597.cpp"

string _rs() { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

double evalTree(Node* node) {
    if (isdigit(node->val)) return node->val - '0';
    double l = evalTree(node->left);
    double r = evalTree(node->right);
    switch (node->val) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
    }
    return 0;
}

// simple infix evaluator for verification
double evalExpr(const string& s) {
    stack<double> nums;
    stack<char> ops;
    auto prec = [](char c) { return (c=='+'||c=='-') ? 1 : (c=='*'||c=='/') ? 2 : 0; };
    auto apply = [&]() {
        char op = ops.top(); ops.pop();
        double r = nums.top(); nums.pop();
        double l = nums.top(); nums.pop();
        double res = 0;
        if (op=='+') res = l+r;
        else if (op=='-') res = l-r;
        else if (op=='*') res = l*r;
        else res = l/r;
        nums.push(res);
    };
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) nums.push(c - '0');
        else if (c=='(') ops.push(c);
        else if (c==')') { while (ops.top()!='(') apply(); ops.pop(); }
        else if (c=='+'||c=='-'||c=='*'||c=='/') {
            while (!ops.empty() && ops.top()!='(' && prec(ops.top())>=prec(c)) apply();
            ops.push(c);
        }
    }
    while (!ops.empty()) apply();
    return nums.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s = _rs();
        Solution sol;
        Node* root = sol.expTree(s);
        double treeVal = evalTree(root);
        double exprVal = evalExpr(s);
        bool ok = fabs(treeVal - exprVal) < 1e-6;
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
