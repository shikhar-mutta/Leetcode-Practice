#include <bits/stdc++.h>
using namespace std;
#include "359.cpp"

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
vector<string> _rargs() {
    string s; getline(cin,s);
    vector<string> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>=2) cur+=c; }
        else if (c==']') { if(dep>=2) cur+=c; dep--; if(dep==1){ v.push_back(cur); cur=""; } }
        else if (dep>=2) cur+=c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> ops = _rvs();
        vector<string> args = _rargs();
        Logger* logger = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "Logger") {
                logger = new Logger();
                out.push_back("null");
            } else if (ops[i] == "shouldPrintMessage") {
                string inner = args[i].substr(1, args[i].size() - 2);
                size_t comma = inner.find(',');
                int ts = stoi(inner.substr(0, comma));
                string msg = inner.substr(comma + 1);
                if (msg.size() >= 2 && msg.front() == '"' && msg.back() == '"') msg = msg.substr(1, msg.size() - 2);
                out.push_back(logger->shouldPrintMessage(ts, msg) ? "true" : "false");
            }
        }
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) {
            if (i) cout << ", ";
            cout << out[i];
        }
        cout << "]\n";
        delete logger;
    }
    return 0;
}
