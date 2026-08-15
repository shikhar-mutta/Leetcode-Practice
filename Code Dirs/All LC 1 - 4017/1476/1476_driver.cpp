#include <bits/stdc++.h>
using namespace std;
#include "1476.cpp"

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

// extracts each top-level arg-group, preserving inner nested brackets
vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
            else if (depth > 2) cur += c;
        } else if (c == ']') {
            if (depth == 2) parts.push_back(cur);
            else if (depth > 2) cur += c;
            depth--;
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

vector<string> splitTopTokens(const string& raw) {
    vector<string> toks;
    int depth = 0;
    string cur;
    for (char c : raw) {
        if (c == '[') { depth++; cur += c; continue; }
        if (c == ']') { depth--; cur += c; continue; }
        if (c == ',' && depth == 0) { toks.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    return toks;
}

vector<vector<int>> parseIntMatrix(const string& s) {
    string body = s;
    if (!body.empty() && body.front() == '[') body = body.substr(1, body.size() - 2);
    vector<vector<int>> rows;
    int dep = 0; string cur;
    for (char c : body) {
        if (c == '[') { dep++; cur = ""; }
        else if (c == ']') {
            vector<int> row;
            stringstream ss(cur);
            string tok;
            while (getline(ss, tok, ',')) if (!tok.empty()) row.push_back(stoi(tok));
            rows.push_back(row);
            dep--;
        } else if (dep > 0) {
            cur += c;
        }
    }
    return rows;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        SubrectangleQueries* sq = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ",";
            auto toks = splitTopTokens(groups[i]);

            if (ops[i] == "SubrectangleQueries") {
                auto rect = parseIntMatrix(toks[0]);
                sq = new SubrectangleQueries(rect);
                cout << "null";
            } else if (ops[i] == "updateSubrectangle") {
                sq->updateSubrectangle(stoi(toks[0]), stoi(toks[1]), stoi(toks[2]), stoi(toks[3]), stoi(toks[4]));
                cout << "null";
            } else if (ops[i] == "getValue") {
                cout << sq->getValue(stoi(toks[0]), stoi(toks[1]));
            }
        }
        cout << "]\n";
        delete sq;
    }
    return 0;
}
