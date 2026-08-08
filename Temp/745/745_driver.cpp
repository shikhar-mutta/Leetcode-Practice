#include <bits/stdc++.h>
using namespace std;
#include "745.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    if (s.size() < 2) return v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        if (c==' ' && !in && cur.empty()) continue;
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<string> parseStrListVar(const string& s) {
    vector<string> v;
    if (s.size() < 2) return v;
    string body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<string> splitTopLevel(const string& line) {
    string inner = line.substr(1, line.size()-2);
    vector<string> groups;
    int depth = 0; string cur;
    for (char c : inner) {
        if (c == '[') { depth++; cur += c; }
        else if (c == ']') { depth--; cur += c; }
        else if (c == ',' && depth == 0) { groups.push_back(cur); cur.clear(); }
        else if (c == ' ' && cur.empty()) continue;
        else cur += c;
    }
    if (!cur.empty()) groups.push_back(cur);
    return groups;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        int n = ops.size();
        string argsLine; getline(cin, argsLine);
        auto groups = splitTopLevel(argsLine);
        WordFilter* wf = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "WordFilter") {
                string g = groups[i]; // like [["apple"]]
                string inner = g.substr(1, g.size()-2); // ["apple"]
                vector<string> words = parseStrListVar(inner);
                wf = new WordFilter(words);
                outputs.push_back("null");
            } else if (ops[i] == "f") {
                string g = groups[i]; // like "a","e"
                string inner = g.substr(1, g.size()-2);
                bool in = false; string cur; vector<string> parts;
                for (char c : inner) {
                    if (c=='"') { in=!in; continue; }
                    if (c==',' && !in) { parts.push_back(cur); cur=""; continue; }
                    cur += c;
                }
                if (!cur.empty()) parts.push_back(cur);
                outputs.push_back(to_string(wf->f(parts[0], parts[1])));
            }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete wf;
    }
    return 0;
}
