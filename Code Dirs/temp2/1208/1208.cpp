// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++)
        {
            maxCost -= abs(s[right] - t[right]);
            if (maxCost < 0)
            {
                maxCost += abs(s[left] - t[left]);
                left++;
            }
        }
        return s.size() - left;
    }
};