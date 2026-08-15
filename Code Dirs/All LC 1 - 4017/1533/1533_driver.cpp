#include <bits/stdc++.h>
using namespace std;
#include "1533.cpp"

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
        auto arr = _rvi();
        ArrayReader reader;
        reader.arr = arr;
        Solution sol;
        cout << sol.getIndex(reader) << "\n";
    }
    return 0;
}
