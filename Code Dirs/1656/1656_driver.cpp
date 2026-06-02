#include <bits/stdc++.h>
using namespace std;
#include "1656.cpp"

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

vector<string> parseMethods(const string& line) {
    vector<string> methods;
    bool in_quote = false;
    string cur;
    for (char c : line) {
        if (c == '"') { if (in_quote) { methods.push_back(cur); cur = ""; } in_quote = !in_quote; }
        else if (in_quote) cur += c;
    }
    return methods;
}

vector<string> parseArgArrays(const string& line) {
    vector<string> args;
    int depth = 0;
    string cur;
    for (int i = 1; i < (int)line.size() - 1; i++) {
        char c = line[i];
        if (c == '[') { if (depth++ == 0) cur = ""; else cur += c; }
        else if (c == ']') { if (--depth == 0) args.push_back(cur); else cur += c; }
        else if (depth > 0) cur += c;
    }
    return args;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string methods_line, args_line;
        getline(cin, methods_line);
        getline(cin, args_line);

        auto methods = parseMethods(methods_line);
        auto arg_arrays = parseArgArrays(args_line);

        OrderedStream* os = nullptr;
        vector<string> all_results;

        for (int i = 0; i < (int)methods.size(); i++) {
            if (methods[i] == "OrderedStream") {
                os = new OrderedStream(stoi(arg_arrays[i]));
            } else if (methods[i] == "insert") {
                string& s = arg_arrays[i];
                int comma = s.find(',');
                int idKey = stoi(s.substr(0, comma));
                int q1 = s.find('"', comma), q2 = s.find('"', q1 + 1);
                string value = s.substr(q1 + 1, q2 - q1 - 1);
                auto res = os->insert(idKey, value);
                for (auto& r : res) all_results.push_back(r);
            }
        }

        for (int i = 0; i < (int)all_results.size(); i++) { if (i) cout << " "; cout << all_results[i]; }
        cout << "\n";
        delete os;
    }
    return 0;
}
