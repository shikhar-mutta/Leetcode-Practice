#include <bits/stdc++.h>
using namespace std;
#include "1273.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }
vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int nodes = _ri();
        auto parent = _rvi();
        auto value = _rvi();
        Solution sol;
        cout << sol.deleteTreeNodes(nodes, parent, value) << "\n";
    }
    return 0;
}
