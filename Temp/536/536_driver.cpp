#include <bits/stdc++.h>
using namespace std;
#include "536.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}

string _serializeTree(TreeNode* root) {
    if (!root) return "";
    vector<string> tokens;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (!node) { tokens.push_back("null"); continue; }
        tokens.push_back(to_string(node->val));
        q.push(node->left);
        q.push(node->right);
    }
    while (!tokens.empty() && tokens.back() == "null") tokens.pop_back();
    string res;
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (i) res += ",";
        res += tokens[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s = _rs();
        Solution sol;
        TreeNode* res = sol.str2tree(s);
        cout << "[" << _serializeTree(res) << "]\n";
    }
    return 0;
}
