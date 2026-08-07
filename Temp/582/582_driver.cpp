#include <bits/stdc++.h>
using namespace std;
#include "582.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto pid = _rvi();
        auto ppid = _rvi();
        int kill = _ri();
        Solution sol;
        auto res = sol.killProcess(pid, ppid, kill);
        sort(res.begin(), res.end());
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) { if(i) cout << ","; cout << res[i]; }
        cout << "]\n";
    }
    return 0;
}
