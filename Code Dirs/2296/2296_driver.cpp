#include <bits/stdc++.h>
using namespace std;
#include "2296.cpp"

// ── read helpers ──────────────────────────────────────────────────
int           _ri()  { string s; getline(cin,s); return stoi(s); }
long long     _rll() { string s; getline(cin,s); return stoll(s); }
double        _rd()  { string s; getline(cin,s); return stod(s); }
bool          _rb()  { string s; getline(cin,s); return s=="true"||s=="1"; }
string        _rs()  { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
vector<long long> _rvll() {
    string s; getline(cin,s);
    vector<long long> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoll(t)); }
    return v;
}
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
vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}

// parse a line like [[],["leetcode"],[4]] -> token list per inner array
static vector<vector<string>> _rargs2() {
    string s; getline(cin, s);
    vector<vector<string>> res;
    int dep = 0; string cur; vector<string> inner;
    auto flush = [&]() {
        string t = cur;
        while (!t.empty() && (t.front() == ' ' || t.front() == '"')) t.erase(t.begin());
        while (!t.empty() && (t.back()  == ' ' || t.back()  == '"')) t.pop_back();
        if (!t.empty()) inner.push_back(t);
        cur.clear();
    };
    for (char c : s) {
        if (c == '[') dep++;
        else if (c == ']') {
            if (dep == 2) { flush(); res.push_back(inner); inner.clear(); }
            dep--;
        } else if (dep == 2) {
            if (c == ',') flush();
            else cur += c;
        }
    }
    return res;
}

int main() {
    string countLine;
    getline(cin, countLine); // leading line-count, ignored for design format
    while (cin.peek() != EOF) {
        auto ops  = _rvs();
        auto args = _rargs2();
        TextEditor *ed = nullptr;
        string out = "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) out += ", ";
            const string &op = ops[i];
            auto &a = args[i];
            if (op == "TextEditor")       { ed = new TextEditor(); out += "null"; }
            else if (op == "addText")     { ed->addText(a[0]); out += "null"; }
            else if (op == "deleteText")  { out += to_string(ed->deleteText(stoi(a[0]))); }
            else if (op == "cursorLeft")  { out += "\"" + ed->cursorLeft(stoi(a[0]))  + "\""; }
            else if (op == "cursorRight") { out += "\"" + ed->cursorRight(stoi(a[0])) + "\""; }
        }
        out += "]";
        cout << out << "\n";
    }
    return 0;
}
