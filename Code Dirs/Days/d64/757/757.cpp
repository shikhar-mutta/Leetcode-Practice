// Link: https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1) extra
//  Approach: sort intervals by end ascending (ties by start descending),
//  then greedily pick points from the right end of each interval.
//  Track the last two chosen points p1<p2; if the interval starts after
//  both, add its two rightmost points (e-1, e); if it starts after only
//  p1, add one point (e); otherwise it's already satisfied.
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });

        int ans = 2;
        int a = intervals[0][1] - 1;
        int b = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (l <= a)
            {
                continue;
            }
            else if (l <= b)
            {
                ans++;
                a = b;
                b = r;
            }
            else
            {
                ans += 2;
                a = r - 1;
                b = r;
            }
        }

        return ans;
    }
};