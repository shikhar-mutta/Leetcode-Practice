// Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
//  Approach: Greedy
//  1. Sort the points in descending order of x-coordinate, and for equal x-coordinates, sort in ascending order of y-coordinate.
//  2. Iterate through the sorted points and for each point, check if it can form a valid pair with any of the subsequent points based on the given conditions.
//  3. If a valid pair is found, increment the count and update the y-coordinate to the minimum y-coordinate of the pair to ensure that no other point can be in between them.
//  4. Return the total count of valid pairs found.
class Solution
{
public:
    static bool cmp(const vector<int> &p, const vector<int> &q)
    {
        return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0]; // order by (x, >)
    }
    static int numberOfPairs(vector<vector<int>> &P)
    {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int y = INT_MAX, yi = P[i][1];
            for (int j = i + 1; j < n; j++)
            {
                const int yj = P[j][1];
                if (yj >= yi && y > yj)
                { // P[j] cannot be in between
                    ans++;
                    y = yj;
                    if (yi == yj)
                        break;
                }
            }
        }
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();