// Link: https://leetcode.com/problems/spiral-matrix-iv/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // TC: O(m*n), SC: O(1) extra (besides the output)
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (head && top <= bottom && left <= right)
        {
            for (int j = left; j <= right && head; j++, head = head->next)
                mat[top][j] = head->val;
            top++;
            for (int i = top; i <= bottom && head; i++, head = head->next)
                mat[i][right] = head->val;
            right--;
            if (top <= bottom)
                for (int j = right; j >= left && head; j--, head = head->next)
                    mat[bottom][j] = head->val;
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top && head; i--, head = head->next)
                    mat[i][left] = head->val;
            left++;
        }
        return mat;
    }
};
