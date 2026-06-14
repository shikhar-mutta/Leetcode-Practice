// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// TC: O(n).SC: O(n)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            Node *prev = NULL;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (prev != NULL)
                    prev->next = curr;

                prev = curr;

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        return root;
    }
};