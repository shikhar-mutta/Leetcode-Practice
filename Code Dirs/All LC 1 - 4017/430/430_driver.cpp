#include <bits/stdc++.h>
using namespace std;
#include "430.cpp"

Node* mk(int val) {
    Node* n = new Node();
    n->val = val;
    n->prev = n->next = n->child = nullptr;
    return n;
}

void link(Node* a, Node* b) {
    a->next = b;
    if (b) b->prev = a;
}

void printFlat(Node* head) {
    cout << "[";
    bool first = true;
    while (head) {
        if (!first) cout << ",";
        cout << head->val;
        first = false;
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int tc = 0; tc < t; tc++) {
        string dummy; getline(cin, dummy); // consume placeholder input line

        Node* head = nullptr;
        if (tc == 0) {
            // [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
            vector<Node*> m;
            for (int v : {1,2,3,4,5,6}) m.push_back(mk(v));
            for (int i = 0; i + 1 < (int)m.size(); i++) link(m[i], m[i+1]);
            head = m[0];

            vector<Node*> c1;
            for (int v : {7,8,9,10}) c1.push_back(mk(v));
            for (int i = 0; i + 1 < (int)c1.size(); i++) link(c1[i], c1[i+1]);
            m[2]->child = c1[0];

            vector<Node*> c2;
            for (int v : {11,12}) c2.push_back(mk(v));
            link(c2[0], c2[1]);
            c1[1]->child = c2[0];
        } else if (tc == 1) {
            // [1,2,null,3]
            Node* n1 = mk(1);
            Node* n2 = mk(2);
            link(n1, n2);
            head = n1;
            Node* c = mk(3);
            n1->child = c;
        } else {
            head = nullptr;
        }

        Solution sol;
        Node* res = sol.flatten(head);
        printFlat(res);
    }
    return 0;
}
