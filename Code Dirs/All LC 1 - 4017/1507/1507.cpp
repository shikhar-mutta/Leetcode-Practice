// Link: https://leetcode.com/problems/reformat-date/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string,string> months = {
            {"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},
            {"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},
            {"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}
        };
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;
        while (!day.empty() && !isdigit(day.back())) day.pop_back();
        // strip leading non-digit ordinal prefix isn't needed since day starts with digits
        string dayNum;
        for (char c : day) if (isdigit(c)) dayNum += c;
        if (dayNum.size() == 1) dayNum = "0" + dayNum;
        return year + "-" + months[month] + "-" + dayNum;
    }
};
