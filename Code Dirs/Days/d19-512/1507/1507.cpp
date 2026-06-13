// Link: https://leetcode.com/problems/reformat-date/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    string reformatDate(string date)
    {

        unordered_map<string, string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        // Remove the suffix from the day (e.g., 'st', 'nd', 'rd', 'th')
        day = day.substr(0, day.size() - 2);
        if (day.size() == 1)
            day = "0" + day; // Add leading zero for single-digit days

        string reformattedDate = year + "-" + monthMap[month] + "-" + day;
        return reformattedDate;
    }
};
