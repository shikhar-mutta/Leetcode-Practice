// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n)  SC: O(n)
// Approach: collect list values into a vector, then apply the same upper-middle divide-conquer as the sorted-array version
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (ListNode* p = head; p; p = p->next) nums.push_back(p->val);
        return build(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = (lo + hi + 1) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, lo, mid - 1);
        node->right = build(nums, mid + 1, hi);
        return node;
    }
};
