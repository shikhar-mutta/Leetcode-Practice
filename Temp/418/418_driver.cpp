#include <bits/stdc++.h>
using namespace std;
#include "418.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int rows = _ri();
        int cols = _ri();
        auto sentence = _rvs();
        Solution sol;
        cout << sol.wordsTyping(sentence, rows, cols) << "\n";
    }
    return 0;
}
