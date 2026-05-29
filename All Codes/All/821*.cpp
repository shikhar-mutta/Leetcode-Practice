// Link: https://leetcode.com/problems/shortest-distance-to-a-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> ans(s.size(), 0);
        int prev = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                ans[i] = 0;
                prev = i;
            }
            else
            {
                ans[i] = prev == -1 ? INT_MAX : i - prev;
            }
        }
        prev = -1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                prev = i;
            }
            else if (prev != -1)
            {
                ans[i] = min(ans[i], prev - i);
            }
        }
        return ans;
    }
};
