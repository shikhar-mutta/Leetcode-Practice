#include <bits/stdc++.h>
using namespace std;
#include "1858.cpp"

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto words = _rvs();
        Solution sol;
        string res = sol.longestWord(words);
        cout << "\"" << res << "\"\n";
    }
    return 0;
}
