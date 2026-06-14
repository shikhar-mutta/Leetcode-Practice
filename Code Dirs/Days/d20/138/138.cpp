// Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    // TC: O(n), SC: O(1)
    void insertAtBetween(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
    }
    void copyRandom(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    void removeOriginal(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = temp->next;
            temp->next = copyNode->next;
            if (copyNode->next != NULL)
                copyNode->next = copyNode->next->next;
            temp = temp->next;
        }
    }
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        insertAtBetween(head);
        copyRandom(head);

        Node *copyHead = head->next;
        removeOriginal(head);

        return copyHead;
    }
};