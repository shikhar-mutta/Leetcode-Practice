// Link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(1)
//   Approach:
//     1. We can iterate through each query and for each query, we can iterate through each point and check if the point is inside the circle defined by the query.
//     2. We can use the distance formula to check if the point is inside the circle.
//     3. We can keep a count of the number of points inside the circle and return the count for each query.
//     4. Finally, we can return the result array containing the count of points inside the circle for each query.
class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = points.size();
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            int r = queries[i][2];
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                int t1 = abs(a - points[j][0]);
                int t2 = abs(b - points[j][1]);
                if (t1 * t1 + t2 * t2 <= r * r)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};