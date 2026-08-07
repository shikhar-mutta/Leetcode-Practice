// Link: https://leetcode.com/problems/linked-list-random-node/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n) getRandom  SC: O(1)
// Approach: reservoir sampling - walk the list, replace current pick with
// probability 1/i at the i-th node
class Solution {
    ListNode* head;

public:
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int result = 0;
        ListNode* node = head;
        int i = 1;
        while (node) {
            if (rand() % i == 0) result = node->val;
            node = node->next;
            i++;
        }
        return result;
    }
};
