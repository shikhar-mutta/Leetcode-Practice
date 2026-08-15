#include <bits/stdc++.h>
using namespace std;
#include "558.cpp"

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

bool uniform(vector<vector<int>>& grid, int r, int c, int size, int& val) {
    val = grid[r][c];
    for (int i = r; i < r + size; i++)
        for (int j = c; j < c + size; j++)
            if (grid[i][j] != val) return false;
    return true;
}
Node* build(vector<vector<int>>& grid, int r, int c, int size) {
    int val;
    if (uniform(grid, r, c, size, val)) return new Node(val == 1, true);
    int half = size / 2;
    Node* tl = build(grid, r, c, half);
    Node* tr = build(grid, r, c + half, half);
    Node* bl = build(grid, r + half, c, half);
    Node* br = build(grid, r + half, c + half, half);
    return new Node(true, false, tl, tr, bl, br);
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
        auto grid1 = _rvvi();
        auto grid2 = _rvvi();
        Node* t1 = build(grid1, 0, 0, grid1.size());
        Node* t2 = build(grid2, 0, 0, grid2.size());
        Solution sol;
        Node* res = sol.intersect(t1, t2);
        vector<string> out;
        printNode(res, out);
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ",";
            cout << out[i];
        }
        cout << "]\n";
    }
    return 0;
}
