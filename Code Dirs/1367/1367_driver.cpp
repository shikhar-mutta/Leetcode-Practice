#include <bits/stdc++.h>
using namespace std;
#include "1367.cpp"

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

// read a bracketed line like [1,4,null,2] into raw string tokens
static vector<string> _rtok() {
    string s; getline(cin, s);
    vector<string> v;
    if (s.size() < 2) return v;
    stringstream ss(s.substr(1, s.size() - 2));
    string t;
    while (getline(ss, t, ',')) {
        while (!t.empty() && t.front() == ' ') t.erase(t.begin());
        while (!t.empty() && t.back()  == ' ') t.pop_back();
        if (!t.empty()) v.push_back(t);
    }
    return v;
}

static ListNode *buildList(const vector<string> &tok) {
    ListNode *head = nullptr, *tail = nullptr;
    for (const string &x : tok) {
        ListNode *node = new ListNode(stoi(x));
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

static TreeNode *buildTree(const vector<string> &tok) {
    if (tok.empty() || tok[0] == "null") return nullptr;
    TreeNode *root = new TreeNode(stoi(tok[0]));
    queue<TreeNode *> q; q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)tok.size()) {
        TreeNode *cur = q.front(); q.pop();
        if (i < (int)tok.size() && tok[i] != "null") { cur->left  = new TreeNode(stoi(tok[i])); q.push(cur->left);  }
        i++;
        if (i < (int)tok.size() && tok[i] != "null") { cur->right = new TreeNode(stoi(tok[i])); q.push(cur->right); }
        i++;
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        ListNode *head = buildList(_rtok());
        TreeNode *root = buildTree(_rtok());
        Solution sol;
        auto res = sol.isSubPath(head, root);
        cout << (res ? "true" : "false") << "\n";
    }
    return 0;
}
