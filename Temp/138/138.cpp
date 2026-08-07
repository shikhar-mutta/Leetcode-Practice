// Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// TC: O(n)  SC: O(n)
// Approach: hash map from original node to its clone; two passes — first clone all nodes (val only),
// then wire next/random pointers using the map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> clone;
        for (Node* cur = head; cur; cur = cur->next) clone[cur] = new Node(cur->val);
        for (Node* cur = head; cur; cur = cur->next) {
            clone[cur]->next = cur->next ? clone[cur->next] : nullptr;
            clone[cur]->random = cur->random ? clone[cur->random] : nullptr;
        }
        return clone[head];
    }
};
