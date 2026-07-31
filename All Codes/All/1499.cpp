// Link: https://leetcode.com/problems/max-value-of-equation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach: We can use a priority queue to solve this problem. We can iterate through the points and for each point, we can check if there is any point in the priority queue that is within the range of k. If there is, we can calculate the value of the equation and update the maximum value. Finally, we can return the maximum value.
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int max_val = INT_MIN;
        for (auto &point : points)
        {
            int xj = point[0];
            int yj = point[1];
            while (!pq.empty() && xj - pq.top().second > k)
                pq.pop();
            if (!pq.empty())
                max_val = max(max_val, pq.top().first + yj + xj);
            pq.push({yj - xj, xj});
        }
        return max_val;
    }
};