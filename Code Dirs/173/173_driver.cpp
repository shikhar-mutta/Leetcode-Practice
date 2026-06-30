#include <bits/stdc++.h>
using namespace std;
#include "173.cpp"

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

// Build a tree from LeetCode level-order tokens (with "null" markers).
TreeNode* buildTree(const vector<string>& tok) {
    if (tok.empty() || tok[0]=="null") return nullptr;
    TreeNode* root = new TreeNode(stoi(tok[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (!q.empty() && i < tok.size()) {
        TreeNode* n = q.front(); q.pop();
        if (i < tok.size()) { if (tok[i]!="null") { n->left  = new TreeNode(stoi(tok[i])); q.push(n->left); }  i++; }
        if (i < tok.size()) { if (tok[i]!="null") { n->right = new TreeNode(stoi(tok[i])); q.push(n->right); } i++; }
    }
    return root;
}

int main() {
    string countLine; getline(cin, countLine);   // leading count — ignore
    auto ops = _rvs();                            // ["BSTIterator","next",...]
    string argsLine; getline(cin, argsLine);      // [[[7,3,...]],[],[],...]

    // Extract the constructor's tree tokens: the first depth-3 [..] group.
    vector<string> treeTok;
    size_t p = argsLine.find('[');
    p = argsLine.find('[', p+1);
    p = argsLine.find('[', p+1);
    if (p != string::npos) {
        string cur;
        for (size_t q = p+1; q < argsLine.size() && argsLine[q] != ']'; q++) {
            char c = argsLine[q];
            if (c == ',') { treeTok.push_back(cur); cur=""; }
            else cur += c;
        }
        if (!cur.empty()) treeTok.push_back(cur);
    }
    TreeNode* root = buildTree(treeTok);

    BSTIterator* it = nullptr;
    vector<string> out;
    for (const string& op : ops) {
        if (op == "BSTIterator")   { it = new BSTIterator(root); out.push_back("null"); }
        else if (op == "next")     { out.push_back(to_string(it->next())); }
        else if (op == "hasNext")  { out.push_back(it->hasNext() ? "true" : "false"); }
    }

    cout << "[";
    for (size_t i = 0; i < out.size(); i++) { if (i) cout << ", "; cout << out[i]; }
    cout << "]\n";
    return 0;
}
