#include <bits/stdc++.h>
using namespace std;
#include "3508.cpp"

vector<string> splitTopLevel(const string& s) {
    vector<string> out;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 1) cur += c; }
        else if (c == ']') { dep--; if (dep >= 1) cur += c; else { out.push_back(cur); cur=""; } }
        else if (c == ',' && dep == 1) { out.push_back(cur); cur=""; }
        else cur += c;
    }
    return out;
}

vector<string> parseStrList(const string& s) {
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<int> parseIntList(const string& s) {
    vector<int> v;
    if (s.size() <= 2) return v;
    auto body = s.substr(1, s.size()-2);
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string opsLine, argsLine;
        getline(cin, opsLine);
        getline(cin, argsLine);
        vector<string> ops = parseStrList(opsLine);
        vector<string> argGroups = splitTopLevel(argsLine);

        Router* router = nullptr;
        cout << "[";
        bool first = true;
        for (size_t i = 0; i < ops.size(); i++) {
            if (!first) cout << ", ";
            first = false;
            vector<int> args = parseIntList(argGroups[i]);
            if (ops[i] == "Router") {
                router = new Router(args[0]);
                cout << "null";
            } else if (ops[i] == "addPacket") {
                bool r = router->addPacket(args[0], args[1], args[2]);
                cout << (r ? "true" : "false");
            } else if (ops[i] == "forwardPacket") {
                auto r = router->forwardPacket();
                cout << "[";
                for (size_t k = 0; k < r.size(); k++) { if (k) cout << ", "; cout << r[k]; }
                cout << "]";
            } else if (ops[i] == "getCount") {
                int r = router->getCount(args[0], args[1], args[2]);
                cout << r;
            }
        }
        cout << "]\n";
        delete router;
    }
    return 0;
}
