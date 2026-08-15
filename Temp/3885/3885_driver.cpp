#include <bits/stdc++.h>
using namespace std;
#include "3885.cpp"

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

// splits a top-level bracketed list into its bracketed items, e.g.
// "[[[[5,7],[2,7],[9,4]]],[],[9,7],[],[]]" ->
// ["[[5,7],[2,7],[9,4]]", "[]", "[9,7]", "[]", "[]"]
vector<string> splitTopLevel(const string& s) {
    string inner = s.substr(1, s.size() - 2); // strip outer [ ]
    vector<string> items;
    int depth = 0;
    string cur;
    for (char c : inner) {
        if (c == '[') { depth++; cur += c; }
        else if (c == ']') { depth--; cur += c; if (depth == 0) { items.push_back(cur); cur = ""; } }
        else if (c == ',' && depth == 0) { /* separator between items, cur should be empty */ }
        else { cur += c; }
    }
    return items;
}

vector<int> parseIntList(const string& tok) {
    // tok like "[9,7]" or "[]"
    vector<int> v;
    string body = tok.substr(1, tok.size() - 2);
    stringstream ss(body);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

vector<vector<int>> parseEvents(const string& tok) {
    // tok like "[[5,7],[2,7],[9,4]]"
    vector<vector<int>> res;
    for (auto& row : splitTopLevel(tok)) res.push_back(parseIntList(row));
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto argItems = splitTopLevel(argsLine);

        vector<string> results;
        EventManager* mgr = nullptr;
        for (int i = 0; i < (int)ops.size(); i++) {
            const string& op = ops[i];
            const string& item = argItems[i];
            if (op == "EventManager") {
                auto innerArgs = splitTopLevel(item); // one arg: the events list
                auto events = parseEvents(innerArgs[0]);
                mgr = new EventManager(events);
                results.push_back("null");
            } else if (op == "updatePriority") {
                auto a = parseIntList(item);
                mgr->updatePriority(a[0], a[1]);
                results.push_back("null");
            } else if (op == "pollHighest") {
                results.push_back(to_string(mgr->pollHighest()));
            }
        }
        delete mgr;

        cout << "[";
        for (int i = 0; i < (int)results.size(); i++) {
            if (i) cout << ", ";
            cout << results[i];
        }
        cout << "]\n";
    }
    return 0;
}
