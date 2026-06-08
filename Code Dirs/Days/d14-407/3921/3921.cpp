// Link: https://leetcode.com/problems/score-validator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    vector<int> scoreValidator(vector<string> &events)
    {
        int count = 0, totalScore = 0;
        for (const string &event : events)
        {
            if (event == "WD")
                totalScore++;
            else if (event == "NB")
                totalScore++;
            else if (event == "W")
                count++;
            else
                totalScore += stoi(event);

            if (count == 10)
                break;
        }
        return vector<int>{totalScore, count};
    }
};
