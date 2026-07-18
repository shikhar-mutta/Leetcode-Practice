// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    // TC: O(N). SC: O(1).
    Node *flatten(Node *head)
    {
        if (!head || !head->next && !head->child)
            return head;

        Node *curr = head;
        while (curr)
        {
            if (curr->child)
            {
                Node *nextNode = curr->next;
                Node *childHead = flatten(curr->child);
                curr->next = childHead;
                childHead->prev = curr; // DLL property
                curr->child = nullptr;  // Detach the child pointer
                // Attach the nextNode to the end of the child last node
                Node *tail = childHead;
                while (tail->next)
                    tail = tail->next;
                tail->next = nextNode;
                if (nextNode)
                    nextNode->prev = tail;

                curr = childHead;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};