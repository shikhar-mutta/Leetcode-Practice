// Link: https://leetcode.com/problems/day-of-the-week/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    //  Approach:
    //   1. Use Zeller's Congruence algorithm to calculate the day of the week for a given date.
    //   2. Adjust the month and year if the month is January or February.
    //   3. Calculate the day of the week using the formula and return the corresponding day name from the array of day names.
    //   4. The formula is: h = (q + 13(m + 1)/5 + K + K/4 + J/4 + 5J) mod 7
    //      where:
    //      h is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
    //      q is the day of the month
    //      m is the month (3 = March, 4 = April, ..., 12 = December, January and February are counted as months 13 and 14 of the previous year)
    //      K is the year of the century (year mod 100)
    //      J is the zero-based century (actually floor(year/100))
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