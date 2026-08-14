#include <bits/stdc++.h>
using namespace std;
#include "3242.cpp"

// ── read helpers ──────────────────────────────────────────────────
vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

// parses one line like: [[[[0,1,2],[3,4,5],[6,7,8]]],[1],[4],[4],[8]]
// into a list of raw argument-list strings (one per call), each still bracketed.
vector<string> splitArgLists(const string& s) {
    // s starts with '[' and ends with ']', body is comma-separated bracketed groups at depth 1
    vector<string> res;
    int n = s.size();
    int i = 1; // skip outer '['
    while (i < n - 1) {
        if (s[i] == ',') { i++; continue; }
        int start = i;
        int dep = 0;
        while (i < n - 1) {
            if (s[i] == '[') dep++;
            else if (s[i] == ']') { dep--; if (dep == 0) { i++; break; } }
            i++;
        }
        res.push_back(s.substr(start, i - start));
    }
    return res;
}

vector<vector<int>> parseGrid(const string& s) {
    // s like [[0,1,2],[3,4,5],[6,7,8]]
    vector<vector<int>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row; stringstream ss(cur);
                string t; while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur = "";
            }
        } else if (dep == 2) cur += c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto argLists = splitArgLists(argsLine);

        NeighborSum* obj = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i > 0) cout << ", ";
            if (ops[i] == "NeighborSum") {
                // argLists[i] = [[[0,1,2],[3,4,5],[6,7,8]]]
                string inner = argLists[i].substr(1, argLists[i].size()-2); // strip outer []
                auto grid = parseGrid(inner);
                obj = new NeighborSum(grid);
                cout << "null";
            } else {
                // argLists[i] = [1]
                string inner = argLists[i].substr(1, argLists[i].size()-2);
                int value = stoi(inner);
                int res = (ops[i] == "adjacentSum") ? obj->adjacentSum(value) : obj->diagonalSum(value);
                cout << res;
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
