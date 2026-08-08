#include <bits/stdc++.h>
using namespace std;
#include "1861.cpp"

vector<vector<char>> _rvvc() {
    string s; getline(cin, s);
    vector<vector<char>> grid;
    int depth = 0; string cur;
    bool inStr = false;
    for (char c : s) {
        if (c == '"') { inStr = !inStr; continue; }
        if (inStr) { cur += c; continue; }
        if (c == '[') { depth++; if (depth == 2) cur = ""; continue; }
        if (c == ']') {
            depth--;
            if (depth == 1) {
                vector<char> row(cur.begin(), cur.end());
                grid.push_back(row);
            }
            continue;
        }
        if (c == ',' ) continue;
    }
    return grid;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto boxGrid = _rvvc();
        Solution sol;
        auto res = sol.rotateTheBox(boxGrid);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ",";
            cout << "\"";
            for (char c : res[i]) cout << c;
            cout << "\"";
        }
        cout << "]\n";
    }
    return 0;
}
