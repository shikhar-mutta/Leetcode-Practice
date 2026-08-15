#include <bits/stdc++.h>
using namespace std;
#include "1656.cpp"

vector<string> _rvs() {
    string s; getline(cin, s);
    vector<string> v;
    auto body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<vector<string>> extractGroupsRaw(const string& s) {
    vector<vector<string>> res;
    int depth = 0; string cur;
    bool inStr = false;
    for (char c : s) {
        if (c == '"') { inStr = !inStr; cur += c; continue; }
        if (inStr) { cur += c; continue; }
        if (c == '[') { depth++; if (depth == 2) cur = ""; continue; }
        if (c == ']') {
            depth--;
            if (depth == 1) {
                vector<string> args;
                string tok; bool str = false;
                for (char cc : cur) {
                    if (cc == '"') { str = !str; continue; }
                    if (cc == ',' && !str) { args.push_back(tok); tok = ""; continue; }
                    tok += cc;
                }
                if (!tok.empty() || !cur.empty()) args.push_back(tok);
                res.push_back(args);
            }
            continue;
        }
        if (depth == 2) cur += c;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        OrderedStream* os = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto& op = ops[i];
            auto& args = groups[i];
            if (op == "OrderedStream") {
                os = new OrderedStream(stoi(args[0]));
                outputs.push_back("null");
            } else if (op == "insert") {
                int idKey = stoi(args[0]);
                string value = args[1];
                auto res = os->insert(idKey, value);
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) {
                    if (j) s += ",";
                    s += "\"" + res[j] + "\"";
                }
                s += "]";
                outputs.push_back(s);
            }
        }
        delete os;

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";
    }
    return 0;
}
