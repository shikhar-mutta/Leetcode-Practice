#include <bits/stdc++.h>
using namespace std;
#include "2901.cpp"

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

bool oneDiff(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int diff = 0;
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] != b[i] && ++diff > 1) return false;
    return diff == 1;
}

int trueMaxLen(vector<string>& words, vector<int>& groups) {
    int n = words.size();
    vector<int> dp(n, 1);
    int best = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (groups[j] != groups[i] && oneDiff(words[j], words[i]))
                dp[i] = max(dp[i], dp[j] + 1);
        best = max(best, dp[i]);
    }
    return best;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto words = _rvs();
        auto groups = _rvi();
        Solution sol;
        auto res = sol.getWordsInLongestSubsequence(words, groups);

        bool ok = true;
        for (int i = 1; i + 0 < (int)res.size() && ok; i++)
            if (!oneDiff(res[i - 1], res[i])) ok = false;

        if (ok) {
            int n = words.size();
            int ptr = 0, prevGroup = INT_MIN;
            for (auto& w : res) {
                int found = -1;
                for (int idx = ptr; idx < n; idx++) {
                    if (words[idx] == w && groups[idx] != prevGroup) { found = idx; break; }
                }
                if (found == -1) { ok = false; break; }
                ptr = found + 1;
                prevGroup = groups[found];
            }
        }

        if (ok) ok = ((int)res.size() == trueMaxLen(words, groups));

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
