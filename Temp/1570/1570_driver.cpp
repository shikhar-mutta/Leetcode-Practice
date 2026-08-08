#include <bits/stdc++.h>
using namespace std;
#include "1570.cpp"

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
        auto nums1 = _rvi();
        auto nums2 = _rvi();
        SparseVector v1(nums1), v2(nums2);
        cout << v1.dotProduct(v2) << "\n";
    }
    return 0;
}
