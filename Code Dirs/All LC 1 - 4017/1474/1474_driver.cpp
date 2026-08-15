#include <bits/stdc++.h>
using namespace std;
#include "1474.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

ListNode* _rlist() {
    auto nums = _rvi();
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : nums) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        ListNode* head = _rlist();
        int m = _ri();
        int n = _ri();
        Solution sol;
        auto res = sol.deleteNodes(head, m, n);
        bool first = true;
        while (res) {
            if (!first) cout << " ";
            cout << res->val;
            first = false;
            res = res->next;
        }
        cout << "\n";
    }
    return 0;
}
