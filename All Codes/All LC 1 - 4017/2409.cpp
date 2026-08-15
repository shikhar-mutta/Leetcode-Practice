// Link: https://leetcode.com/problems/count-days-spent-together/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    //  convert "MM-DD" to a day-of-year index (non-leap year)
    int dayOfYear(const string &d)
    {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mm = stoi(d.substr(0, 2)), dd = stoi(d.substr(3, 2));
        int total = dd;
        for (int i = 0; i < mm - 1; ++i)
            total += days[i]; // add full prior months
        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        // overlap of two date intervals = latest start .. earliest end (inclusive)
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));
        return max(0, end - start + 1);
    }
};
