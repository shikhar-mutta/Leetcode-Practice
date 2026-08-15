// Link: https://leetcode.com/problems/spiral-matrix-iv/description/

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (head && top <= bottom && left <= right) {
            for (int c = left; c <= right && head; c++) { grid[top][c] = head->val; head = head->next; }
            top++;
            for (int r = top; r <= bottom && head; r++) { grid[r][right] = head->val; head = head->next; }
            right--;
            if (top <= bottom) {
                for (int c = right; c >= left && head; c--) { grid[bottom][c] = head->val; head = head->next; }
                bottom--;
            }
            if (left <= right) {
                for (int r = bottom; r >= top && head; r--) { grid[r][left] = head->val; head = head->next; }
                left++;
            }
        }
        return grid;
    }
};
