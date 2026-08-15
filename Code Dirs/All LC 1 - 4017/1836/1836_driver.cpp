#include <bits/stdc++.h>
using namespace std;
#include "1836.cpp"

vector<int> _rvi() {
    string s; getline(cin, s);
    vector<int> v; stringstream ss(s.substr(1, s.size() - 2));
    string t; while (getline(ss, t, ',')) { if (!t.empty()) v.push_back(stoi(t)); }
    return v;
}

ListNode* build(vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto v = _rvi();
        ListNode* head = build(v);
        Solution sol;
        ListNode* res = sol.deleteDuplicatesUnsorted(head);
        cout << "[";
        bool first = true;
        while (res) {
            if (!first) cout << ",";
            first = false;
            cout << res->val;
            res = res->next;
        }
        cout << "]\n";
    }
    return 0;
}
