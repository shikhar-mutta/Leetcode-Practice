#include <bits/stdc++.h>
using namespace std;
#include "138.cpp"

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

vector<pair<int,int>> _rPairsWithNull() {
    string s; getline(cin,s);
    vector<pair<int,int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                stringstream ss(cur);
                string t; vector<string> parts;
                while(getline(ss,t,',')) if(!t.empty()) parts.push_back(t);
                int val = stoi(parts[0]);
                int rnd = (parts[1] == "null") ? -1 : stoi(parts[1]);
                v.push_back({val, rnd});
                cur="";
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
        auto pairs = _rPairsWithNull();
        int n = pairs.size();
        vector<Node*> nodes(n);
        for (int i = 0; i < n; i++) nodes[i] = new Node(pairs[i].first);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) nodes[i]->next = nodes[i+1];
            if (pairs[i].second >= 0) nodes[i]->random = nodes[pairs[i].second];
        }
        Node* head = n > 0 ? nodes[0] : nullptr;
        Solution sol;
        auto res = sol.copyRandomList(head);

        unordered_map<Node*,int> idx;
        int k = 0;
        for (Node* cur = res; cur; cur = cur->next) idx[cur] = k++;
        cout << "[";
        bool first = true;
        for (Node* cur = res; cur; cur = cur->next) {
            if (!first) cout << ",";
            first = false;
            cout << "[" << cur->val << ",";
            if (cur->random) cout << idx[cur->random];
            else cout << "null";
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
