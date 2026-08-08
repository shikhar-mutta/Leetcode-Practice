// Link: https://leetcode.com/problems/linked-list-components/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC: O(n) SC: O(k)
// Approach: put nums in a set; walk the list counting the number of maximal runs of consecutive nodes whose values are all in the set.
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        bool inRun = false;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (s.count(cur->val)) {
                if (!inRun) { count++; inRun = true; }
            } else {
                inRun = false;
            }
        }
        return count;
    }
};
