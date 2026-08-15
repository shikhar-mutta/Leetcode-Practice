#include <bits/stdc++.h>
using namespace std;
#include "1352.cpp"

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto argGroups = extractGroupsRaw(argsLine);

        ProductOfNumbers* pn = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ",";
            vector<int> nums;
            stringstream ss(argGroups[i]);
            string tok;
            while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));

            if (ops[i] == "ProductOfNumbers") {
                pn = new ProductOfNumbers();
                cout << "null";
            } else if (ops[i] == "add") {
                pn->add(nums[0]);
                cout << "null";
            } else if (ops[i] == "getProduct") {
                cout << pn->getProduct(nums[0]);
            }
        }
        cout << "]\n";
        delete pn;
    }
    return 0;
}
