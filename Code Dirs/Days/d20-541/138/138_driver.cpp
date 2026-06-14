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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    // reads [[val,null],[val,idx],...] into pairs; -1 means null random
    auto readInput = []() -> vector<pair<int,int>> {
        string s; getline(cin, s);
        vector<pair<int,int>> res;
        int i = 0, n = s.size();
        while (i < n) {
            // find inner '[' followed by digit or '-'
            while (i < n && !(s[i] == '[' && i+1 < n && (isdigit(s[i+1]) || s[i+1] == '-'))) i++;
            if (i >= n) break;
            i++; // skip '['
            int sign = 1;
            if (s[i] == '-') { sign = -1; i++; }
            int val = 0;
            while (i < n && isdigit(s[i])) val = val*10 + (s[i++]-'0');
            val *= sign;
            i++; // skip ','
            int rnd = -1;
            if (s[i] == 'n') { i += 4; }
            else { rnd = 0; while (i < n && isdigit(s[i])) rnd = rnd*10 + (s[i++]-'0'); }
            res.push_back({val, rnd});
        }
        return res;
    };
    while (t--) {
        auto pairs = readInput();
        // build nodes
        vector<Node*> nodes;
        for (auto& [v, _] : pairs) nodes.push_back(new Node(v));
        for (int i = 0; i < (int)nodes.size(); i++) {
            if (i+1 < (int)nodes.size()) nodes[i]->next = nodes[i+1];
            if (pairs[i].second != -1) nodes[i]->random = nodes[pairs[i].second];
        }
        Node* head = nodes.empty() ? nullptr : nodes[0];
        Solution sol;
        auto res = sol.copyRandomList(head);
        // print result: [[val,null|idx],...]
        // build index map for result nodes
        vector<Node*> resNodes;
        for (Node* cur = res; cur; cur = cur->next) resNodes.push_back(cur);
        unordered_map<Node*, int> idx;
        for (int i = 0; i < (int)resNodes.size(); i++) idx[resNodes[i]] = i;
        cout << "[";
        for (int i = 0; i < (int)resNodes.size(); i++) {
            if (i) cout << ",";
            cout << "[" << resNodes[i]->val << ",";
            if (resNodes[i]->random) cout << idx[resNodes[i]->random];
            else cout << "null";
            cout << "]";
        }
        cout << "]\n";
    }
    return 0;
}
