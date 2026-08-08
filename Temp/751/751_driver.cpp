#include <bits/stdc++.h>
using namespace std;
#include "751.cpp"

string _rs() {
    string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string ip = _rs();
        int n = _ri();
        Solution sol;
        auto res = sol.ipToCIDR(ip, n);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) { if(i) cout << ","; cout << "\"" << res[i] << "\""; }
        cout << "]\n";
    }
    return 0;
}
