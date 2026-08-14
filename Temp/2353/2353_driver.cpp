#include <bits/stdc++.h>
using namespace std;
#include "2353.cpp"

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

vector<vector<vector<string>>> _rargsNested() {
    string s; getline(cin,s);
    vector<vector<vector<string>>> perOp;
    int dep = 0; bool inq = false;
    vector<vector<string>> opSlots;
    vector<string> slot;
    string tok;
    for (char c : s) {
        if (c == '"') {
            if (!inq) { tok = ""; }
            else {
                if (dep == 2) opSlots.push_back({tok});
                else if (dep == 3) slot.push_back(tok);
                tok = "";
            }
            inq = !inq;
            continue;
        }
        if (inq) { tok += c; continue; }
        if (c == '[') { dep++; continue; }
        if (c == ']') {
            if (dep == 3) {
                if (!tok.empty()) { slot.push_back(tok); tok = ""; }
                opSlots.push_back(slot); slot.clear();
            } else if (dep == 2) {
                if (!tok.empty()) { opSlots.push_back({tok}); tok = ""; }
                perOp.push_back(opSlots); opSlots.clear();
            }
            dep--;
            continue;
        }
        if ((dep == 2 || dep == 3) && (isdigit(c) || c == '-')) tok += c;
        else if (dep == 2 && c == ',') {
            if (!tok.empty()) { opSlots.push_back({tok}); tok = ""; }
        } else if (dep == 3 && c == ',') {
            if (!tok.empty()) { slot.push_back(tok); tok = ""; }
        }
    }
    return perOp;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rargsNested();
        FoodRatings* sol = nullptr;
        vector<string> out;
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == "FoodRatings") {
                vector<string> foods = args[i][0];
                vector<string> cuisines = args[i][1];
                vector<int> ratings;
                for (auto& r : args[i][2]) ratings.push_back(stoi(r));
                sol = new FoodRatings(foods, cuisines, ratings);
                out.push_back("null");
            } else if (ops[i] == "changeRating") {
                sol->changeRating(args[i][0][0], stoi(args[i][1][0]));
                out.push_back("null");
            } else if (ops[i] == "highestRated") {
                out.push_back("\"" + sol->highestRated(args[i][0][0]) + "\"");
            }
        }
        delete sol;
        cout << "[";
        for (int i = 0; i < (int)out.size(); i++) { if (i) cout << ", "; cout << out[i]; }
        cout << "]\n";
    }
    return 0;
}
