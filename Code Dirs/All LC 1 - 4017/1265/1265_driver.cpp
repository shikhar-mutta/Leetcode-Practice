#include <bits/stdc++.h>
using namespace std;
#include "1265.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}

bool g_first;

class MockListNode : public ImmutableListNode {
public:
    int val;
    MockListNode* next;
    MockListNode(int v, MockListNode* n) : val(v), next(n) {}
    void printValue() override {
        if (!g_first) cout << " ";
        g_first = false;
        cout << val;
    }
    ImmutableListNode* getNext() override { return next; }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto nums = _rvi();
        MockListNode* head = nullptr;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            head = new MockListNode(nums[i], head);
        }
        g_first = true;
        Solution sol;
        sol.printLinkedListInReverse(head);
        cout << "\n";
    }
    return 0;
}
