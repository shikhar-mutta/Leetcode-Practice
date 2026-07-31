#include <bits/stdc++.h>
using namespace std;
#include "1032.cpp"

vector<string> parseOps(const string& s) {
    vector<string> v;
    string body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<string> splitTopLevel(const string& s) {
    vector<string> parts;
    int depth = 0; bool inQ = false; string cur;
    for (char c : s) {
        if (c == '"') inQ = !inQ;
        if (!inQ) {
            if (c == '[') depth++;
            else if (c == ']') depth--;
        }
        if (c == ',' && depth == 0 && !inQ) { parts.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) parts.push_back(cur);
    return parts;
}

string unquote(string s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') return s.substr(1, s.size() - 2);
    return s;
}

vector<string> parseStringArray(string s) {
    s = s.substr(1, s.size() - 2);
    vector<string> parts = splitTopLevel(s);
    vector<string> res;
    for (auto& p : parts) res.push_back(unquote(p));
    return res;
}

int main() {
    string tmp;
    getline(cin, tmp);
    string opsLine, argsLine;
    getline(cin, opsLine);
    getline(cin, argsLine);
    auto ops = parseOps(opsLine);

    string body = argsLine.substr(1, argsLine.size() - 2);
    vector<string> callArgsRaw = splitTopLevel(body);

    StreamChecker* sc = nullptr;
    string out = "[null";
    for (size_t i = 0; i < ops.size(); i++) {
        string raw = callArgsRaw[i];
        raw = raw.substr(1, raw.size() - 2); // strip outer [ ]
        auto args = splitTopLevel(raw);
        if (ops[i] == "StreamChecker") {
            vector<string> words = parseStringArray(args[0]);
            sc = new StreamChecker(words);
        } else if (ops[i] == "query") {
            char letter = unquote(args[0])[0];
            bool r = sc->query(letter);
            out += r ? ", true" : ", false";
        }
    }
    out += "]";
    cout << out << "\n";
    return 0;
}
