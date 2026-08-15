#include <bits/stdc++.h>
using namespace std;
#include "302.cpp"

vector<vector<char>> _rvvc() {
    string s; getline(cin,s);
    vector<vector<char>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<char> row;
                bool in=false;
                for (char rc : cur) {
                    if (rc=='"') { in=!in; continue; }
                    if (!in) continue;
                    row.push_back(rc);
                }
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
        auto image = _rvvc();
        string s; getline(cin, s);
        stringstream ss(s.substr(1, s.size()-2));
        string tok;
        getline(ss, tok, ',');
        int x = stoi(tok);
        getline(ss, tok, ',');
        int y = stoi(tok);
        Solution sol;
        cout << sol.minArea(image, x, y) << "\n";
    }
    return 0;
}
