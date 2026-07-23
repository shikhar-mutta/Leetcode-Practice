// Link: https://leetcode.com/problems/day-of-the-week/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        static const string names[] = {"Sunday", "Monday", "Tuesday",
                                       "Wednesday", "Thursday", "Friday",
                                       "Saturday"};

        if (month < 3)
        {
            month += 12;
            year--;
        }

        int K = year % 100;
        int J = year / 100;
        int h = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
        return names[(h + 6) % 7];
    }
};