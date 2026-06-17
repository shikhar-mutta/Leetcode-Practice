// Link: https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    string maximumTime(string time)
    {
        // hours tens: 2 unless that would force the ones digit above 3
        if (time[0] == '?')
            time[0] = (time[1] == '?' || time[1] <= '3') ? '2' : '1';
        // hours ones: max is 3 when tens is 2, else 9
        if (time[1] == '?')
            time[1] = (time[0] == '2') ? '3' : '9';
        if (time[3] == '?')
            time[3] = '5'; // minutes tens max
        if (time[4] == '?')
            time[4] = '9'; // minutes ones max
        return time;
    }
};
