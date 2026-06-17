// Link: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    int convertTime(string current, string correct)
    {
        // "hh:mm" -> total minutes
        auto mins = [](const string &t)
        { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)); };
        int diff = mins(correct) - mins(current);

        int ops = 0;
        // greedily take the largest increment each step
        for (int step : {60, 15, 5, 1})
        {
            ops += diff / step;
            diff %= step;
        }
        return ops;
    }
};
