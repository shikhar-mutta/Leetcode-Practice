#include <bits/stdc++.h>
using namespace std;
#include "1580.cpp"

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
        auto boxes = _rvi();
        auto warehouse = _rvi();
        Solution sol;
        cout << sol.maxBoxesInWarehouse(boxes, warehouse) << "\n";
    }
    return 0;
}
