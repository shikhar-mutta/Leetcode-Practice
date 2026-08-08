#include <bits/stdc++.h>
using namespace std;
#include "708.cpp"

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
        auto vals = _rvi();
        int insertVal = _ri();
        Node* head = nullptr;
        if (!vals.empty()) {
            head = new Node(vals[0]);
            Node* cur = head;
            for (size_t i = 1; i < vals.size(); i++) {
                cur->next = new Node(vals[i]);
                cur = cur->next;
            }
            cur->next = head;
        }
        Solution sol;
        Node* res = sol.insert(head, insertVal);
        vector<int> out;
        if (res) {
            Node* cur = res;
            do { out.push_back(cur->val); cur = cur->next; } while (cur != res);
        }
        cout << "[";
        for (size_t i = 0; i < out.size(); i++) { if(i) cout << ","; cout << out[i]; }
        cout << "]\n";
    }
    return 0;
}
