// Link: https://leetcode.com/problems/consecutive-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxPower(string s)
    {
        int maxPower = 1, currentPower = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
                ++currentPower;
            else
                currentPower = 1;
            maxPower = max(maxPower, currentPower);
        }
        return maxPower;
    }
};
