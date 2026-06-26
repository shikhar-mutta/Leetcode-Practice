#include <bits/stdc++.h>
using namespace std;
#include "703.cpp"

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

// Split the outer [...] args line into its top-level bracket groups,
// e.g. "[[3,[4,5,8,2]],[3],[5]]" -> {"[3,[4,5,8,2]]", "[3]", "[5]"}.
vector<string> _splitGroups(const string& line) {
    string body = line.substr(1, line.size() - 2); // drop outer [ ]
    vector<string> groups;
    int dep = 0; string cur;
    for (char c : body) {
        if (c == '[') { if (dep == 0) cur.clear(); dep++; cur += c; }
        else if (c == ']') { dep--; cur += c; if (dep == 0) groups.push_back(cur); }
        else if (dep > 0) cur += c;
    }
    return groups;
}

// Pull every integer out of a string (handles nested brackets/commas).
vector<int> _ints(const string& s) {
    vector<int> v; int i = 0, n = s.size();
    while (i < n) {
        if (s[i] == '-' || isdigit((unsigned char)s[i])) {
            int j = i + 1;
            while (j < n && isdigit((unsigned char)s[j])) j++;
            v.push_back(stoi(s.substr(i, j - i)));
            i = j;
        } else i++;
    }
    return v;
}

int main() {
    int t;
    cin >> t;          // number of input lines that follow (2 per test case)
    cin.ignore();
    int cases = t / 2;
    while (cases--) {
        auto ops = _rvs();                 // ["KthLargest","add",...]
        string argsLine; getline(cin, argsLine);
        auto groups = _splitGroups(argsLine);

        // First group constructs the object: k + initial nums array.
        auto ctor = _ints(groups[0]);
        int k = ctor[0];
        vector<int> nums(ctor.begin() + 1, ctor.end());
        KthLargest obj(k, nums);

        cout << "[null";
        for (size_t i = 1; i < ops.size(); i++) {
            int val = _ints(groups[i])[0];
            cout << ", " << obj.add(val);
        }
        cout << "]\n";
    }
    return 0;
}
