#include <bits/stdc++.h>
using namespace std;
#include "1826.cpp"

vector<int> _rvi() {
    string s; getline(cin, s);
    vector<int> v; stringstream ss(s.substr(1, s.size() - 2));
    string t; while (getline(ss, t, ',')) { if (!t.empty()) v.push_back(stoi(t)); }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto s1 = _rvi();
        auto s2 = _rvi();
        Solution sol;
        cout << sol.badSensor(s1, s2) << "\n";
    }
    return 0;
}
