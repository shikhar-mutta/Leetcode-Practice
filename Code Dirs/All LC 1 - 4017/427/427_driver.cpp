#include <bits/stdc++.h>
using namespace std;
#include "427.cpp"

vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}

void printNode(Node* node, vector<string>& out) {
    if (!node) return;
    out.push_back("[" + string(node->isLeaf ? "1" : "0") + "," + string(node->val ? "1" : "0") + "]");
    if (!node->isLeaf) {
        printNode(node->topLeft, out);
        printNode(node->topRight, out);
        printNode(node->bottomLeft, out);
        printNode(node->bottomRight, out);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto grid = _rvvi();
        Solution sol;
        Node* root = sol.construct(grid);
        vector<string> out;
        printNode(root, out);
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ",";
            cout << out[i];
        }
        cout << "]\n";
    }
    return 0;
}
