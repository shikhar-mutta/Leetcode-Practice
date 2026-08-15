// Link: https://leetcode.com/problems/traffic-signal-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    string trafficSignal(int timer)
    {
        if (timer == 0)
            return "Green";
        else if (timer == 30)
            return "Orange";
        else if (timer > 30 && timer <= 90)
            return "Red";
        return "Invalid";
    }
};
