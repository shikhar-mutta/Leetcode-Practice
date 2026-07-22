// Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n).
    // SC: O(1).
    // Approach:
    //  1. We can use a stack to keep track of the number of available slots for nodes in the binary tree. We start with one available slot for the root node. For each node in the preorder serialization, we decrement the number of available slots by one. If the node is not a null node (represented by "#"), we increment the number of available slots by two, since a non-null node has two children. If at any point the number of available slots becomes negative, we return false, since it means that there are more nodes than available slots. Finally, we check if the number of available slots is zero, which means that all nodes have been placed in the binary tree and the serialization is valid.
    bool isValidSerialization(string preorder)
    {
        stringstream ss(preorder);
        string tok;
        int slots = 1;
        while (getline(ss, tok, ','))
        {
            if (slots <= 0)
                return false;
            slots--;
            if (tok != "#")
                slots += 2;
        }
        return slots == 0;
    }
};
