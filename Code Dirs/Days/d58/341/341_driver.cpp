#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    NestedInteger() : isInt(true), val(0) {}
    NestedInteger(int v) : isInt(true), val(v) {}
    NestedInteger(const vector<NestedInteger>& l) : isInt(false), val(0), list(l) {}

    bool isInteger() const { return isInt; }
    int getInteger() const { return val; }
    const vector<NestedInteger>& getList() const { return list; }

private:
    bool isInt;
    int val;
    vector<NestedInteger> list;
};

#include "341.cpp"

NestedInteger _parseNested(const string& s, int& pos) {
    if (s[pos] == '[') {
        pos++;
        vector<NestedInteger> lst;
        while (s[pos] != ']') {
            lst.push_back(_parseNested(s, pos));
            if (s[pos] == ',') pos++;
        }
        pos++;
        return NestedInteger(lst);
    } else {
        int start = pos;
        if (s[pos] == '-') pos++;
        while (pos < (int)s.size() && isdigit(s[pos])) pos++;
        return NestedInteger(stoi(s.substr(start, pos - start)));
    }
}
vector<NestedInteger> _parseTopLevel(const string& s) {
    int pos = 0;
    NestedInteger root = _parseNested(s, pos);
    return root.getList();
}

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        vector<NestedInteger> nestedList = _parseTopLevel(line);
        NestedIterator it(nestedList);
        vector<int> result;
        while (it.hasNext())
            result.push_back(it.next());
        cout << "[";
        for (int i = 0; i < (int)result.size(); i++) {
            if (i) cout << ",";
            cout << result[i];
        }
        cout << "]\n";
    }
    return 0;
}
