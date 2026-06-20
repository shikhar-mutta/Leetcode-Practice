// Link: https://leetcode.com/problems/binary-watch/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(12*60) = O(1), SC: O(60) = O(1)
    vector<string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn < 0 || turnedOn > 8)
            return {};

        vector<string> res;
        vector<int> dp(60, 0);
        for (int i = 0; i < 60; i++)
            dp[i] = dp[i >> 1] + (i & 1);

        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                // total LEDs on = set bits in hour + set bits in minute
                if (dp[h] + dp[m] == turnedOn)
                {
                    string t = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    res.push_back(t);
                }
        return res;
    }
};
