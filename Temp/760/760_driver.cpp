#include <bits/stdc++.h>
using namespace std;
#include "760.cpp"

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
        Solution sol;
        auto res = sol.anagramMappings(nums1, nums2);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) { if(i) cout << ","; cout << res[i]; }
        cout << "]\n";
    }
    return 0;
}
