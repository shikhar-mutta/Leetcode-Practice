// Link: https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: Convert both times to seconds and return the difference.
class Solution
{
public:
    int secondsBetweenTimes(string startTime, string endTime)
    {
        int startsec = (startTime[6] - '0') * 10 + startTime[7] - '0';
        int endsec = (endTime[6] - '0') * 10 + endTime[7] - '0';

        int startmin = (startTime[3] - '0') * 10 + startTime[4] - '0';
        int endmin = (endTime[3] - '0') * 10 + endTime[4] - '0';

        int starthr = (startTime[0] - '0') * 10 + startTime[1] - '0';
        int endhr = (endTime[0] - '0') * 10 + endTime[1] - '0';

        int ss = starthr * 3600 + startmin * 60 + startsec;
        int es = endhr * 3600 + endmin * 60 + endsec;

        int ans = es - ss;

        return ans;
    }
};