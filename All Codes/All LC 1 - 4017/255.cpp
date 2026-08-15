// Link: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: simulate the preorder traversal with a stack; a lower bound tracks the last node we
// "returned" from on the right — any subsequent value must exceed it, since BST preorder only
// dips below a value while still inside its left subtree
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int lowerBound = INT_MIN;
        for (int x : preorder) {
            if (x < lowerBound) return false;
            while (!st.empty() && st.top() < x) {
                lowerBound = st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};
