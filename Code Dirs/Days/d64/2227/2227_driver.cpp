#include <bits/stdc++.h>
using namespace std;
#include "2227.cpp"

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
        vector<string> ops = _rvs();
        // parse args line: bracket-depth split into top-level groups
        string s; getline(cin, s);
        vector<string> argGroups;
        int dep = 0; string cur;
        for (char c : s) {
            if (c == '[') { dep++; if (dep > 1) cur += c; }
            else if (c == ']') { dep--; if (dep >= 1) cur += c; if (dep == 1) { argGroups.push_back(cur); cur = ""; } }
            else if (dep > 1) cur += c;
        }
        Encrypter* obj = nullptr;
        vector<string> results;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "Encrypter") {
                // argGroups[i] = [["a","b","c","d"],["ei","zf","ei","am"],["abcd",...]]
                vector<vector<string>> parts;
                int d = 0; string c2;
                for (char ch : argGroups[i]) {
                    if (ch == '[') { d++; if (d > 2) c2 += ch; }
                    else if (ch == ']') { d--; if (d >= 2) c2 += ch;
                        if (d == 1) {
                            vector<string> row;
                            bool in = false; string tok;
                            for (char rc : c2) {
                                if (rc == '"') { in = !in; continue; }
                                if (rc == ',' && !in) { row.push_back(tok); tok = ""; continue; }
                                tok += rc;
                            }
                            if (!tok.empty()) row.push_back(tok);
                            parts.push_back(row);
                            c2 = "";
                        }
                    } else if (d > 1) c2 += ch;
                }
                vector<char> keys;
                for (auto& x : parts[0]) keys.push_back(x[0]);
                vector<string> values = parts[1];
                vector<string> dictionary = parts[2];
                obj = new Encrypter(keys, values, dictionary);
                results.push_back("null");
            } else if (ops[i] == "encrypt") {
                string arg = argGroups[i];
                if (arg.size() >= 2 && arg.front() == '[') arg = arg.substr(1, arg.size() - 2);
                if (arg.size() >= 2 && arg.front() == '"') arg = arg.substr(1, arg.size() - 2);
                results.push_back("\"" + obj->encrypt(arg) + "\"");
            } else if (ops[i] == "decrypt") {
                string arg = argGroups[i];
                if (arg.size() >= 2 && arg.front() == '[') arg = arg.substr(1, arg.size() - 2);
                if (arg.size() >= 2 && arg.front() == '"') arg = arg.substr(1, arg.size() - 2);
                results.push_back(to_string(obj->decrypt(arg)));
            }
        }
        delete obj;
        cout << "[";
        for (int i = 0; i < (int)results.size(); i++) {
            if (i) cout << ", ";
            cout << results[i];
        }
        cout << "]\n";
    }
    return 0;
}
