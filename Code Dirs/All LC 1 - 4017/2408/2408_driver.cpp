#include <bits/stdc++.h>
using namespace std;
#include "2408.cpp"

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

struct Val {
    bool isArr = false;
    string str;
    vector<Val> arr;
};

Val parseValue(const string &s, size_t &i) {
    Val v;
    if (s[i] == '[') {
        v.isArr = true;
        i++;
        if (s[i] == ']') { i++; return v; }
        while (true) {
            v.arr.push_back(parseValue(s, i));
            if (s[i] == ',') { i++; continue; }
            if (s[i] == ']') { i++; break; }
        }
        return v;
    }
    if (s[i] == '"') {
        i++;
        string cur;
        while (s[i] != '"') cur += s[i++];
        i++;
        v.str = cur;
        return v;
    }
    string cur;
    while (i < s.size() && s[i] != ',' && s[i] != ']') cur += s[i++];
    v.str = cur;
    return v;
}

vector<string> toStrArr(const Val &v) {
    vector<string> r;
    for (auto &e : v.arr) r.push_back(e.str);
    return r;
}
vector<int> toIntArr(const Val &v) {
    vector<int> r;
    for (auto &e : v.arr) r.push_back(stoi(e.str));
    return r;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        size_t idx = 0;
        Val allArgs = parseValue(argsLine, idx);

        SQL* sql = nullptr;
        vector<string> outputs;

        for (size_t i = 0; i < ops.size(); i++) {
            string &op = ops[i];
            Val &args = allArgs.arr[i];
            if (op == "SQL") {
                vector<string> names = toStrArr(args.arr[0]);
                vector<int> columns = toIntArr(args.arr[1]);
                sql = new SQL(names, columns);
                outputs.push_back("null");
            } else if (op == "ins") {
                string name = args.arr[0].str;
                vector<string> row = toStrArr(args.arr[1]);
                bool res = sql->insertRow(name, row);
                outputs.push_back(res ? "true" : "false");
            } else if (op == "rmv") {
                string name = args.arr[0].str;
                int rowId = stoi(args.arr[1].str);
                sql->removeRow(name, rowId);
                outputs.push_back("null");
            } else if (op == "sel") {
                string name = args.arr[0].str;
                int rowId = stoi(args.arr[1].str);
                int colId = stoi(args.arr[2].str);
                string res = sql->selectCell(name, rowId, colId);
                outputs.push_back("\"" + res + "\"");
            } else if (op == "exp") {
                string name = args.arr[0].str;
                vector<string> res = sql->exportTable(name);
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) {
                    if (j) s += ",";
                    s += "\"" + res[j] + "\"";
                }
                s += "]";
                outputs.push_back(s);
            }
        }

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";

        delete sql;
    }
    return 0;
}
