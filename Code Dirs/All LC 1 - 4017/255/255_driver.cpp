#include <bits/stdc++.h>
using namespace std;
#include "255.cpp"

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
        auto preorder = _rvi();
        Solution sol;
        auto res = sol.verifyPreorder(preorder);
        cout << (res ? "true" : "false") << "\n";
    }
    return 0;
}
