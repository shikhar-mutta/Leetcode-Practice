#include <bits/stdc++.h>
using namespace std;
#include "382.cpp"

vector<string> parseOps(const string& s) {
    vector<string> ops;
    string body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { ops.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) ops.push_back(cur);
    return ops;
}

// Extracts [1,2,3] from "[[[1,2,3]],[],[],...]"
vector<int> parseHeadList(const string& s) {
    size_t start = s.find("[[[");
    if (start == string::npos) return {};
    start += 2;
    size_t end = s.find(']', start + 1);
    vector<int> v;
    stringstream ss(s.substr(start + 1, end - start - 1));
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

int main() {
    srand(42);
    int t; cin >> t; cin.ignore();
    while (t--) {
        string opsLine, argsLine;
        getline(cin, opsLine);
        getline(cin, argsLine);

        auto ops  = parseOps(opsLine);
        auto head = build(parseHeadList(argsLine));

        Solution* obj = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            if (ops[i] == "Solution") {
                obj = new Solution(head);
                cout << "null";
            } else if (ops[i] == "getRandom") {
                cout << obj->getRandom();
            }
        }
        cout << "]\n";
        delete obj;
    }
    return 0;
}
