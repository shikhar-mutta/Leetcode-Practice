// Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        vector<int> s;
        for (auto &p : points)
            s.push_back(p[0]);

        sort(s.begin(), s.end());
        int max_width = 0, n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (max_width < s[i] - s[i - 1])
                max_width = s[i] - s[i - 1];
        }
        return max_width;
    }
};
