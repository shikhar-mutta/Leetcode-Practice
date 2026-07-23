#include <bits/stdc++.h>
using namespace std;
#include "919.cpp"

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

vector<string> _rargsRaw() {
    string line; getline(cin, line);
    vector<string> raw;
    int dep = 0; string cur;
    for (char c : line) {
        if (c == '[') {
            dep++;
            if (dep >= 3) cur += c;
        } else if (c == ']') {
            if (dep >= 3) cur += c;
            dep--;
            if (dep == 1) { raw.push_back(cur); cur = ""; }
        } else if (c == ',') {
            if (dep >= 2) cur += c;
        } else {
            if (dep >= 2) cur += c;
        }
    }
    return raw;
}

TreeNode* _buildTreeFromStr(const string &s) {
    if (s.empty()) return nullptr;
    string body = s.substr(1, s.size() - 2);
    vector<string> toks; string cur;
    for (char c : body) {
        if (c == ',') { toks.push_back(cur); cur = ""; }
        else cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    if (toks.empty() || toks[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(toks[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (i < toks.size() && !q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < toks.size()) { if (toks[i] != "null") { cur->left = new TreeNode(stoi(toks[i])); q.push(cur->left); } i++; }
        if (i < toks.size()) { if (toks[i] != "null") { cur->right = new TreeNode(stoi(toks[i])); q.push(cur->right); } i++; }
    }
    return root;
}

string _serializeTreeSpaced(TreeNode* root) {
    if (!root) return "[]";
    vector<string> arr;
    arr.push_back(to_string(root->val));
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (cur->left) { arr.push_back(to_string(cur->left->val)); q.push(cur->left); }
        else arr.push_back("null");
        if (cur->right) { arr.push_back(to_string(cur->right->val)); q.push(cur->right); }
        else arr.push_back("null");
    }
    while (!arr.empty() && arr.back() == "null") arr.pop_back();
    string s = "[";
    for (size_t i = 0; i < arr.size(); i++) { if (i) s += ", "; s += arr[i]; }
    s += "]";
    return s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto rawArgs = _rargsRaw();
        CBTInserter* inserter = nullptr;
        vector<string> outputs;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "CBTInserter") {
                TreeNode* root = _buildTreeFromStr(rawArgs[i]);
                inserter = new CBTInserter(root);
                outputs.push_back("null");
            } else if (ops[i] == "insert") {
                int val = stoi(rawArgs[i]);
                outputs.push_back(to_string(inserter->insert(val)));
            } else if (ops[i] == "get_root") {
                outputs.push_back(_serializeTreeSpaced(inserter->get_root()));
            }
        }
        cout << "[";
        for (int i = 0; i < (int)outputs.size(); i++) { if (i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete inserter;
    }
    return 0;
}
