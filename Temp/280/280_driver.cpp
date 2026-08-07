#include <bits/stdc++.h>
using namespace std;
#include "280.cpp"

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
        vector<int> nums = _rvi();
        Solution sol;
        sol.wiggleSort(nums);
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i) cout << ",";
            cout << nums[i];
        }
        cout << "\n";
    }
    return 0;
}
