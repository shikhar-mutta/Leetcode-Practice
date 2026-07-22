// Link: https://leetcode.com/problems/valid-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), since we are only dealing with a fixed number of points (4 points), the time complexity is constant.
    // SC: O(1), since we are using a fixed amount of extra space to store the distances between the points, the space complexity is also constant.
    // Approach:
    // 1. We first store the four points in a vector of vectors for easier manipulation.
    // 2. We then calculate the squared distances between all pairs of points and store them in a vector.
    // 3. We sort the distances to easily identify the four equal sides and the two equal diagonals.
    // 4. Finally, we check the conditions for a valid square: no coincident points, four equal sides, two equal diagonals, and the relationship between the side length and diagonal length (diagonal² = 2·side²).
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> p = {p1, p2, p3, p4};
        vector<long long> d;

        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
            {
                long long dx = p[i][0] - p[j][0];
                long long dy = p[i][1] - p[j][1];
                d.push_back(dx * dx + dy * dy);
            }

        sort(d.begin(), d.end());

        return d[0] > 0 &&                                     // no coincident points
               d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && // 4 equal sides
               d[4] == d[5] &&                                 // 2 equal diagonals
               d[4] == 2 * d[0];                               // diagonal² = 2·side²
    }
};