#include <bits/stdc++.h>
using namespace std;
#include "1257.cpp"

string _rs() { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

vector<vector<string>> _rvvs() {
    string s; getline(cin,s);
    vector<vector<string>> v;
    int dep = 0;
    vector<string> row;
    string cur;
    bool in = false;
    for (char c : s) {
        if (c == '"') { in = !in; continue; }
        if (in) { cur += c; continue; }
        if (c == '[') {
            dep++;
        } else if (c == ']') {
            if (dep == 2) {
                if (!cur.empty()) { row.push_back(cur); cur = ""; }
                v.push_back(row);
                row.clear();
            }
            dep--;
        } else if (c == ',') {
            if (dep == 2 && !cur.empty()) { row.push_back(cur); cur = ""; }
        }
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto regions = _rvvs();
        string region1 = _rs();
        string region2 = _rs();
        Solution sol;
        cout << sol.findSmallestRegion(regions, region1, region2) << "\n";
    }
    return 0;
}
