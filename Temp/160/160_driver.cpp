#include <bits/stdc++.h>
using namespace std;
#include "160.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto A = _rvi();
        auto B = _rvi();
        int skipA = _ri();
        int skipB = _ri();

        vector<ListNode*> tail;
        for (int i = skipA; i < (int)A.size(); i++) tail.push_back(new ListNode(A[i]));
        for (int i = 0; i + 1 < (int)tail.size(); i++) tail[i]->next = tail[i+1];

        vector<ListNode*> a;
        for (int i = 0; i < skipA; i++) a.push_back(new ListNode(A[i]));
        for (int i = 0; i + 1 < (int)a.size(); i++) a[i]->next = a[i+1];
        ListNode* headA = a.empty() ? (tail.empty() ? nullptr : tail[0]) : a[0];
        if (!a.empty() && !tail.empty()) a.back()->next = tail[0];

        vector<ListNode*> b;
        for (int i = 0; i < skipB; i++) b.push_back(new ListNode(B[i]));
        for (int i = 0; i + 1 < (int)b.size(); i++) b[i]->next = b[i+1];
        ListNode* headB = b.empty() ? (tail.empty() ? nullptr : tail[0]) : b[0];
        if (!b.empty() && !tail.empty()) b.back()->next = tail[0];

        Solution sol;
        auto res = sol.getIntersectionNode(headA, headB);
        if (res) cout << res->val << "\n";
        else cout << "no intersection\n";
    }
    return 0;
}
