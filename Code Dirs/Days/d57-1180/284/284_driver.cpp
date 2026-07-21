#include <bits/stdc++.h>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};

struct Iterator::Data {
    vector<int> nums;
    size_t idx;
    Data(const vector<int>& n) : nums(n), idx(0) {}
};

Iterator::Iterator(const vector<int>& nums) : data(new Data(nums)) {}
Iterator::Iterator(const Iterator& iter) : data(new Data(*iter.data)) {}
Iterator::~Iterator() { delete data; }
int Iterator::next() { return data->nums[data->idx++]; }
bool Iterator::hasNext() const { return data->idx < data->nums.size(); }

#include "284.cpp"

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

// Splits an args line like "[[[1,2,3]],[],[],[],[],[]]" into the raw
// (still-bracketed) argument-list text for each op: {"[1,2,3]", "", "", ...}
vector<string> _rargs() {
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
        } else {
            if (dep >= 2) cur += c;
        }
    }
    return raw;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargs();

        vector<int> nums;
        {
            string &s = args[0];
            if (!s.empty()) {
                stringstream ss(s.substr(1, s.size() - 2));
                string tok;
                while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));
            }
        }

        PeekingIterator* it = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "PeekingIterator") {
                it = new PeekingIterator(nums);
                outputs.push_back("null");
            } else if (ops[i] == "next") {
                outputs.push_back(to_string(it->next()));
            } else if (ops[i] == "peek") {
                outputs.push_back(to_string(it->peek()));
            } else if (ops[i] == "hasNext") {
                outputs.push_back(it->hasNext() ? "true" : "false");
            }
        }
        delete it;

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";
    }
    return 0;
}
