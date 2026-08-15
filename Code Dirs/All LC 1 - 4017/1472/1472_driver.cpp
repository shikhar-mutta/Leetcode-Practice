#include <bits/stdc++.h>
using namespace std;
#include "1472.cpp"

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

vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
        } else if (c == ']') {
            depth--;
            if (depth == 1) parts.push_back(cur);
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

string stripQuotes(string s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') return s.substr(1, s.size() - 2);
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        BrowserHistory* bh = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ",";
            string g = groups[i];

            if (ops[i] == "BrowserHistory") {
                bh = new BrowserHistory(stripQuotes(g));
                cout << "null";
            } else if (ops[i] == "visit") {
                bh->visit(stripQuotes(g));
                cout << "null";
            } else if (ops[i] == "back") {
                cout << "\"" << bh->back(stoi(g)) << "\"";
            } else if (ops[i] == "forward") {
                cout << "\"" << bh->forward(stoi(g)) << "\"";
            }
        }
        cout << "]\n";
        delete bh;
    }
    return 0;
}
