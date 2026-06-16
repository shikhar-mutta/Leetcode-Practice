// Link: https://leetcode.com/problems/number-of-valid-clock-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    int countTime(string t)
    {
        int h = (t[0] == '?' && t[1] == '?') ? 24 : (t[0] == '?' ? (t[1] <= '3' ? 3 : 2) : (t[1] == '?' ? (t[0] == '2' ? 4 : 10) : 1));
        int m = (t[3] == '?' && t[4] == '?') ? 60 : (t[3] == '?' ? 6 : (t[4] == '?' ? 10 : 1));
        return h * m;
    }
};