#include <bits/stdc++.h>
using namespace std;
#include "284.cpp"

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
        PeekingIterator it(nums);
        vector<int> res;
        while (it.hasNext()) {
            res.push_back(it.peek());
            res.push_back(it.next());
        }
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << res[i];
        }
        cout << "]\n";
    }
    return 0;
}
