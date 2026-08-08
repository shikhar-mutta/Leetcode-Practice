#include <bits/stdc++.h>
using namespace std;
#include "1244.cpp"

// ── read helpers ──────────────────────────────────────────────────
int           _ri()  { string s; getline(cin,s); return stoi(s); }
long long     _rll() { string s; getline(cin,s); return stoll(s); }
double        _rd()  { string s; getline(cin,s); return stod(s); }
bool          _rb()  { string s; getline(cin,s); return s=="true"||s=="1"; }
string        _rs()  { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

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

vector<string> splitTopLevel(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') { depth++; if (depth == 2) cur = ""; }
        else if (c == ']') { depth--; if (depth == 1) parts.push_back(cur); }
        else if (depth >= 2) cur += c;
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
        auto argGroups = splitTopLevel(argsLine);

        Leaderboard* lb = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            vector<int> nums;
            stringstream ss(argGroups[i]);
            string tok;
            while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));

            if (ops[i] == "Leaderboard") {
                lb = new Leaderboard();
                cout << "null";
            } else if (ops[i] == "addScore") {
                lb->addScore(nums[0], nums[1]);
                cout << "null";
            } else if (ops[i] == "top") {
                cout << lb->top(nums[0]);
            } else if (ops[i] == "reset") {
                lb->reset(nums[0]);
                cout << "null";
            }
        }
        cout << "]\n";
    }
    return 0;
}
