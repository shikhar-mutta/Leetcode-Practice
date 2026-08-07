// Link: https://leetcode.com/problems/linked-list-cycle-ii/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// TC: O(n)  SC: O(1)
// Approach: Floyd's tortoise and hare to detect a meeting point, then a second pointer from head
// meets the cycle start exactly when they're both `distance-to-cycle-start` steps away
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *ptr = head;
                while (ptr != slow) { ptr = ptr->next; slow = slow->next; }
                return ptr;
            }
        }
        return nullptr;
    }
};
