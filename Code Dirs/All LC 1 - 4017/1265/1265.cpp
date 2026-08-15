// Link: https://leetcode.com/problems/print-immutable-linked-list-in-reverse/description/

#include <bits/stdc++.h>
using namespace std;

class ImmutableListNode {
public:
    virtual void printValue() = 0;
    virtual ImmutableListNode* getNext() = 0;
    virtual ~ImmutableListNode() {}
};

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};
