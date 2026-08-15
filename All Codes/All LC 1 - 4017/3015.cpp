// Link: https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
// Approach: For every pair (i,j), shortest distance is either the direct
// line distance |i-j| or a path routed through the extra edge (x,y) in
// either direction. Each ordered pair (i,j)/(j,i) contributes 2 to ans[d-1].
class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int d = abs(i - j);
                d = min(d, abs(i - x) + 1 + abs(y - j));
                d = min(d, abs(i - y) + 1 + abs(x - j));
                ans[d - 1] += 2;
            }
        }
        return ans;
    }
};
