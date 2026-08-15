#include <bits/stdc++.h>
using namespace std;
#include "690.cpp"

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

vector<Employee*> _remployees() {
    string s; getline(cin,s);
    vector<Employee*> res;
    // format: [[id,importance,[sub1,sub2]],[id,importance,[]]]
    int i = 1, n = s.size(); // start past the outer '['
    while (i < n) {
        if (s[i] == '[') {
            int depth = 0;
            int start = i;
            while (i < n) {
                if (s[i] == '[') depth++;
                else if (s[i] == ']') { depth--; if (depth == 0) { i++; break; } }
                i++;
            }
            string entry = s.substr(start+1, i-1 - (start+1)); // strip entry's own [ ]
            // parse entry
            int j = 0, m = entry.size();
            auto readNum = [&](int& j) {
                int start2 = j;
                while (j < m && (isdigit(entry[j]) || entry[j]=='-')) j++;
                return stoi(entry.substr(start2, j-start2));
            };
            int eid = readNum(j);
            j++; // comma
            int imp = readNum(j);
            j++; // comma
            // now entry[j] should be '['
            Employee* emp = new Employee();
            emp->id = eid;
            emp->importance = imp;
            if (j < m && entry[j] == '[') {
                j++;
                while (j < m && entry[j] != ']') {
                    if (entry[j] == ',') { j++; continue; }
                    int sub = readNum(j);
                    emp->subordinates.push_back(sub);
                }
            }
            res.push_back(emp);
        } else i++;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto employees = _remployees();
        int id = _ri();
        Solution sol;
        auto res = sol.getImportance(employees, id);
        cout << res << "\n";
    }
    return 0;
}
