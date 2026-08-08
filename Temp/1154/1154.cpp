// Link: https://leetcode.com/problems/day-of-the-year/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leap) days[1] = 29;
        int total = day;
        for (int i = 0; i < month - 1; i++) total += days[i];
        return total;
    }
};
