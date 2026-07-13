// Link: https://leetcode.com/problems/diagonal-traverse-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of elements in the 2D vector.
// SC: O(n) for storing the result in a vector.
// Approach:
// 1. Use a queue to perform a BFS-like traversal of the 2D vector.
// 2. Start from the top-left element and push its coordinates into the queue.
// 3. For each element, record its value and push its right neighbor and the cell below it into the queue if they exist.
// 4. Continue this process until the queue is empty, ensuring that we traverse the elements in diagonal order.
// 5. Finally, return the result vector containing the elements in diagonal order.
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &v)
    {
        int n = v.size();        // number of rows
        queue<pair<int, int>> q; // queue for BFS-like traversal
        vector<int> res;         // result array
        q.push({0, 0});          // start at top-left element
        while (!q.empty())
        {
            int i = q.front().first;  // current row index
            int j = q.front().second; // current column index
            q.pop();                  // remove from queue
            res.push_back(v[i][j]);   // record current value
            if (!j && i + 1 < n)      // if at column 0, push cell below
                q.push({i + 1, 0});
            if (j + 1 < v[i].size()) // always try to push right neighbor
                q.push({i, j + 1});
        }
        return res; // return traversal result
    }
};
