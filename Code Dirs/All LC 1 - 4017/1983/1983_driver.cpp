#include <bits/stdc++.h>
using namespace std;
#include "1983.cpp"

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
        auto nums1 = _rvi();
        auto nums2 = _rvi();
        Solution sol;
        cout << sol.widestPairOfIndices(nums1, nums2) << "\n";
    }
    return 0;
}
