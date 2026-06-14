#include <bits/stdc++.h>
using namespace std;
#include "147.cpp"

vector<int> _rvi() {
    string s; getline(cin, s);
    vector<int> v;
    stringstream ss(s.substr(1, s.size() - 2));
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

ListNode* build(const vector<int>& v) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }
    return dummy->next;
}

void print(ListNode* head) {
    cout << "[";
    for (ListNode* cur = head; cur; cur = cur->next) {
        if (cur != head) cout << ",";
        cout << cur->val;
    }
    cout << "]\n";
}

int main() {
    int t; cin >> t; cin.ignore();
    while (t--) {
        auto v = _rvi();
        ListNode* head = build(v);
        Solution sol;
        print(sol.insertionSortList(head));
    }
    return 0;
}
