#include <bits/stdc++.h>
using namespace std;
#include "703.cpp"

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
        KthLargest* kl = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "KthLargest") {
                // group like "[3,[4,5,8,2]]"
                string g = groups[i];
                string inner = g.substr(1, g.size()-2); // "3,[4,5,8,2]"
                size_t bracket = inner.find('[');
                int k = stoi(inner.substr(0, bracket-1));
                string arr = inner.substr(bracket);
                vector<int> nums;
                string body = arr.substr(1, arr.size()-2);
                stringstream ss(body);
                string tok;
                while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));
                kl = new KthLargest(k, nums);
                outputs.push_back("null");
            } else if (ops[i] == "add") {
                string g = groups[i];
                string inner = g.substr(1, g.size()-2);
                int val = stoi(inner);
                outputs.push_back(to_string(kl->add(val)));
            }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete kl;
    }
    return 0;
}
