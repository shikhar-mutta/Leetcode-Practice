// Link: https://leetcode.com/problems/day-of-the-year/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) SC: O(1)
    int dayOfYear(string date)
    {
        int years = stoi(date.substr(0, 4)), months = stoi(date.substr(5, 2)), days = stoi(date.substr(8, 2)), cnt = days, mt;
        for (int i = 1; i < months; i++)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                cnt += 31;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                cnt += 30;
            else if (i == 2)
                if ((years % 100 == 0 ? years % 400 == 0 : years % 4 == 0))
                    cnt += 29;
                else
                    cnt += 28;
        }
        return cnt;
    }
};
