#include <bits/stdc++.h>
using namespace std;
#include "1912.cpp"

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
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        vector<string> argGroups;
        int depth = 0; string cur;
        for (size_t i = 1; i + 1 < argsLine.size(); i++) {
            char c = argsLine[i];
            if (c == '[') { depth++; if (depth == 1) { cur = ""; continue; } }
            if (c == ']') { depth--; if (depth == 0) { argGroups.push_back(cur); continue; } }
            if (depth >= 1) cur += c;
        }

        MovieRentingSystem* sys = nullptr;
        vector<int> flat;
        for (size_t i = 0; i < ops.size(); i++) {
            string& op = ops[i];
            string& g = argGroups[i];
            if (op == "MovieRentingSystem") {
                size_t br = g.find('[');
                int n = stoi(g.substr(0, g.find(',')));
                string inner = g.substr(br + 1, g.size() - br - 2);
                vector<vector<int>> entries;
                int d2 = 0; string c2;
                for (char c : inner) {
                    if (c == '[') { d2++; if (d2 == 1) { c2 = ""; continue; } }
                    if (c == ']') { d2--; if (d2 == 0) {
                            vector<int> row; stringstream ss(c2);
                            string t2; while (getline(ss, t2, ',')) if (!t2.empty()) row.push_back(stoi(t2));
                            entries.push_back(row); continue;
                        } }
                    if (d2 >= 1) c2 += c;
                }
                sys = new MovieRentingSystem(n, entries);
            } else if (op == "search") {
                int movie = stoi(g);
                auto res = sys->search(movie);
                for (int x : res) flat.push_back(x);
            } else if (op == "rent") {
                stringstream ss(g); string a, b;
                getline(ss, a, ','); getline(ss, b, ',');
                sys->rent(stoi(a), stoi(b));
            } else if (op == "drop") {
                stringstream ss(g); string a, b;
                getline(ss, a, ','); getline(ss, b, ',');
                sys->drop(stoi(a), stoi(b));
            } else if (op == "report") {
                auto res = sys->report();
                for (auto& r : res) { flat.push_back(r[0]); flat.push_back(r[1]); }
            }
        }
        for (size_t i = 0; i < flat.size(); i++) { if (i) cout << " "; cout << flat[i]; }
        cout << "\n";
        delete sys;
    }
    return 0;
}
