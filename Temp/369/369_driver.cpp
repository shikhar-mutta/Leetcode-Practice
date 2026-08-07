#include <bits/stdc++.h>
using namespace std;
#include "369.cpp"

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
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : vals) { tail->next = new ListNode(v); tail = tail->next; }
        Solution sol;
        ListNode* res = sol.plusOne(dummy.next);
        cout << "[";
        bool first = true;
        while (res) {
            if (!first) cout << ",";
            cout << res->val;
            first = false;
            res = res->next;
        }
        cout << "]\n";
    }
    return 0;
}
