// Link: https://leetcode.com/problems/determine-if-two-events-have-conflict/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach : use stoi. TC: O(1), SC: O(1).
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int s1 = stoi(event1[0].substr(0, 2)) * 60 + stoi(event1[0].substr(3));
        int e1 = stoi(event1[1].substr(0, 2)) * 60 + stoi(event1[1].substr(3));
        int s2 = stoi(event2[0].substr(0, 2)) * 60 + stoi(event2[0].substr(3));
        int e2 = stoi(event2[1].substr(0, 2)) * 60 + stoi(event2[1].substr(3));
        if (e1 < s2 || e2 < s1)
            return false;
        return true;
    }
};
