#include <bits/stdc++.h>
using namespace std;
#include "529.cpp"

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
vector<vector<char>> _rvvc() {
    string s; getline(cin,s);
    vector<vector<char>> v;
    int dep=0; string cur; bool inStr=false;
    for (char c : s) {
        if (c=='"') { inStr=!inStr; continue; }
        if (inStr) { cur+=c; continue; }
        if (c=='[') { dep++; continue; }
        if (c==']') {
            dep--;
            if (dep==1) {
                vector<char> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(t[0]);
                v.push_back(row); cur="";
            }
            continue;
        }
        if (dep>=2) cur+=c;
    }
    return v;
}
string _serializeVVC(vector<vector<char>>& board) {
    string s = "[";
    for (size_t i = 0; i < board.size(); i++) {
        if (i) s += ",";
        s += "[";
        for (size_t j = 0; j < board[i].size(); j++) {
            if (j) s += ",";
            s += "\"";
            s += board[i][j];
            s += "\"";
        }
        s += "]";
    }
    s += "]";
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto board = _rvvc();
        auto click = _rvi();
        Solution sol;
        auto res = sol.updateBoard(board, click);
        cout << _serializeVVC(res) << "\n";
    }
    return 0;
}
