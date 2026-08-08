// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        for (ListNode* cur = head; cur; cur = cur->next) vals.push_back(cur->val);
        int n = vals.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[st.top()] < vals[i]) {
                res[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
