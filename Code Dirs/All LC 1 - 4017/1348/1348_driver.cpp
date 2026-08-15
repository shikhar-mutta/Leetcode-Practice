#include <bits/stdc++.h>
using namespace std;
#include "1348.cpp"

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

        TweetCounts* tc = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ",";
            auto toks = splitTokens(argGroups[i]);

            if (ops[i] == "TweetCounts") {
                tc = new TweetCounts();
                cout << "null";
            } else if (ops[i] == "recordTweet") {
                tc->recordTweet(stripQuotes(toks[0]), stoi(toks[1]));
                cout << "null";
            } else if (ops[i] == "getTweetCountsPerFrequency") {
                auto res = tc->getTweetCountsPerFrequency(stripQuotes(toks[0]), stripQuotes(toks[1]), stoi(toks[2]), stoi(toks[3]));
                cout << "[";
                for (int j = 0; j < (int)res.size(); j++) {
                    if (j) cout << ",";
                    cout << res[j];
                }
                cout << "]";
            }
        }
        cout << "]\n";
        delete tc;
    }
    return 0;
}
