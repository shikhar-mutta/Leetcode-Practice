// Link: https://leetcode.com/problems/count-number-of-trapezoids-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: Count the number of trapezoids formed by the given points. A trapezoid is formed by two pairs of points with the same y-coordinate. We can count the number of pairs of points with the same y-coordinate and use combinatorics to find the number of trapezoids.
class Solution
{
public:
    static int countTrapezoids(vector<vector<int>> &points)
    {
        const long long mod = 1e9 + 7, n = points.size();
        int *y = (int *)alloca(n * sizeof(int));
        int i = 0;
        for (auto &p : points)
            y[i++] = p[1];
        sort(y, y + n);
        long long sum = 0, c2 = 0, c = 0;
        int f = 1, prev = y[0];
        for (int i = 1; i < n; i++)
        {
            if (prev == y[i])
                f++;
            else
            {
                c = f * (f - 1LL) / 2LL;
                sum += c;
                c2 += c * c;
                f = 1;
                prev = y[i];
            }
        }
        c = f * (f - 1LL) / 2LL;
        sum += c;
        c2 += c * c;
        return (sum * sum - c2) / 2 % mod;
    }
};