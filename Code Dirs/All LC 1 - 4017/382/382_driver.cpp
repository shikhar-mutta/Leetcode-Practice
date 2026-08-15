#include <bits/stdc++.h>
using namespace std;
#include "382.cpp"

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
        auto vals = _rvi();
        int n; cin >> n; cin.ignore();
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : vals) { tail->next = new ListNode(v); tail = tail->next; }
        Solution sol(dummy.next);
        unordered_set<int> allowed(vals.begin(), vals.end());
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int r = sol.getRandom();
            if (!allowed.count(r)) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
