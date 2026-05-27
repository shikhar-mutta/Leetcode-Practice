// Link: https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, n = g.size(), m = s.size();
        while (i < n && j < m)
        {
            if (s[j] >= g[i])
                i++;
            j++;
        }
        return i;
    }
};