#include <bits/stdc++.h>
using namespace std;
#include "1634.cpp"

vector<vector<int>> _rvvi() {
    string s; getline(cin, s);
    vector<vector<int>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row; stringstream ss(cur);
                string t; while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur = "";
            } else if (dep > 0) cur += c;
        } else if (dep > 1) cur += c;
    }
    return v;
}

PolyNode* build(vector<vector<int>>& v) {
    PolyNode dummy(0, 0);
    PolyNode* tail = &dummy;
    for (auto& p : v) {
        tail->next = new PolyNode(p[0], p[1]);
        tail = tail->next;
    }
    return dummy.next;
}

string toStr(PolyNode* head) {
    string s = "[";
    bool first = true;
    while (head) {
        if (!first) s += ",";
        first = false;
        s += "[" + to_string(head->coefficient) + "," + to_string(head->power) + "]";
        head = head->next;
    }
    s += "]";
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto p1raw = _rvvi();
        auto p2raw = _rvvi();
        PolyNode* p1 = build(p1raw);
        PolyNode* p2 = build(p2raw);
        Solution sol;
        PolyNode* res = sol.addPoly(p1, p2);
        cout << toStr(res) << "\n";
    }
    return 0;
}
