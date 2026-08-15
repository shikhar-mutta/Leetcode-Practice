// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach: Greedy
//    1. We can iterate through the boxes from left to right and keep track of the number of balls and the cost to move them to the current box.
//    2. We can then iterate through the boxes from right to left and do the same, adding the costs from both directions to get the total cost for each box.
//    3. Finally, we can return the result vector containing the total costs for each box.
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> res(n, 0);

        int cnt = 0, cost = 0;
        for (int i = 0; i < n; ++i)
        {
            res[i] += cost;
            cnt += boxes[i] - '0';
            cost += cnt;
        }

        cnt = 0;
        cost = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            res[i] += cost;
            cnt += boxes[i] - '0';
            cost += cnt;
        }
        return res;
    }
};