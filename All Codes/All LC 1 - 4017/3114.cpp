// Link: https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    string findLatestTime(string s)
    {
        // 12-hour format HH:MM, HH in 00-11. Greedily pick the largest valid digit.
        if (s[0] == '?')
            s[0] = (s[1] == '?' || s[1] <= '1') ? '1' : '0'; // tens of hour
        if (s[1] == '?')
            s[1] = (s[0] == '1') ? '1' : '9'; // units of hour
        if (s[3] == '?')
            s[3] = '5'; // tens of minute
        if (s[4] == '?')
            s[4] = '9'; // units of minute
        return s;
    }
};
