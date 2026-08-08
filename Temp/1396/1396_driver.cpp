#include <bits/stdc++.h>
using namespace std;
#include "1396.cpp"

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

vector<string> splitTokens(const string& raw) {
    vector<string> toks;
    bool in = false;
    string cur;
    for (char c : raw) {
        if (c == '"') { in = !in; cur += c; continue; }
        if (c == ',' && !in) { toks.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    return toks;
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
        auto argGroups = extractGroupsRaw(argsLine);

        UndergroundSystem* us = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ",";
            auto toks = splitTokens(argGroups[i]);

            if (ops[i] == "UndergroundSystem") {
                us = new UndergroundSystem();
                cout << "null";
            } else if (ops[i] == "checkIn") {
                us->checkIn(stoi(toks[0]), stripQuotes(toks[1]), stoi(toks[2]));
                cout << "null";
            } else if (ops[i] == "checkOut") {
                us->checkOut(stoi(toks[0]), stripQuotes(toks[1]), stoi(toks[2]));
                cout << "null";
            } else if (ops[i] == "getAverageTime") {
                double res = us->getAverageTime(stripQuotes(toks[0]), stripQuotes(toks[1]));
                cout << fixed << setprecision(5) << res;
            }
        }
        cout << "]\n";
        delete us;
    }
    return 0;
}
