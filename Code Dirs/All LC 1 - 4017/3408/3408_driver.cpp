#include <bits/stdc++.h>
using namespace std;
#include "3408.cpp"

// Parses top-level comma-separated groups at depth 1 inside [...]
vector<string> splitArgLists(const string& s) {
    // s is the full line, wrapped in an outer [ ... ]; split the inner
    // top-level comma-separated arg-group strings (each still bracketed).
    string inner = s.substr(1, s.size() - 2);
    vector<string> parts;
    int dep = 0;
    string cur;
    for (char c : inner) {
        if (c == '[') {
            dep++;
            cur += c;
        } else if (c == ']') {
            dep--;
            cur += c;
        } else if (c == ',' && dep == 0) {
            parts.push_back(cur);
            cur = "";
        } else {
            cur += c;
        }
    }
    if (!cur.empty()) parts.push_back(cur);
    return parts;
}

vector<vector<int>> parseGrid(const string& s0) {
    vector<vector<int>> res;
    string s = s0.substr(1, s0.size() - 2); // strip outer matrix brackets
    int i = 0, n = s.size();
    while (i < n) {
        if (s[i] == '[') {
            int j = i + 1;
            string cur;
            while (j < n && s[j] != ']') { cur += s[j]; j++; }
            vector<int> row;
            stringstream ss(cur);
            string t;
            while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
            res.push_back(row);
            i = j + 1;
        } else i++;
    }
    return res;
}

vector<int> parseInts(const string& s) {
    vector<int> res;
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) res.push_back(stoi(t));
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line1; getline(cin, line1);
        string line2; getline(cin, line2);
        vector<string> names = [&]() {
            vector<string> v;
            string body = line1.substr(1, line1.size() - 2);
            bool in = false; string cur;
            for (char c : body) {
                if (c == '"') { in = !in; continue; }
                if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
                cur += c;
            }
            if (!cur.empty()) v.push_back(cur);
            return v;
        }();

        vector<string> argGroups = splitArgLists(line2);

        cout << "[";
        TaskManager* obj = nullptr;
        for (int i = 0; i < (int)names.size(); i++) {
            if (i > 0) cout << ", ";
            string& name = names[i];
            string& args = argGroups[i];
            string inner = args.substr(1, args.size() >= 2 ? args.size() - 2 : 0);
            if (name == "TaskManager") {
                auto grid = parseGrid(inner);
                obj = new TaskManager(grid);
                cout << "null";
            } else if (name == "add") {
                auto v = parseInts(inner);
                obj->add(v[0], v[1], v[2]);
                cout << "null";
            } else if (name == "edit") {
                auto v = parseInts(inner);
                obj->edit(v[0], v[1]);
                cout << "null";
            } else if (name == "rmv") {
                auto v = parseInts(inner);
                obj->rmv(v[0]);
                cout << "null";
            } else if (name == "execTop") {
                cout << obj->execTop();
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
