// Link: https://leetcode.com/problems/number-of-days-between-two-dates/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
class Solution
{
    bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

    int daysInMonth(int m, int y)
    {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (m == 2 && isLeap(y)) ? 29 : days[m - 1];
    }

    int toDays(string &date)
    {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        int total = 0;
        for (int i = 1971; i < y; i++)
            total += isLeap(i) ? 366 : 365;
        for (int i = 1; i < m; i++)
            total += daysInMonth(i, y);
        return total + d;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(toDays(date1) - toDays(date2));
    }
};
