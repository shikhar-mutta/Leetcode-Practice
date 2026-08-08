#include <bits/stdc++.h>
using namespace std;
#include "1669.cpp"

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
        auto v1 = _rvi();
        int a = stoi([]{ string s; getline(cin, s); return s; }());
        int b = stoi([]{ string s; getline(cin, s); return s; }());
        auto v2 = _rvi();

        ListNode* list1 = build(v1);
        ListNode* list2 = build(v2);
        Solution sol;
        ListNode* res = sol.mergeInBetween(list1, a, b, list2);

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
