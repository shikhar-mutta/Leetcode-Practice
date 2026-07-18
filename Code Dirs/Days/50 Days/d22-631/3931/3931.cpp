// Link: https://leetcode.com/problems/check-adjacent-digit-differences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isAdjacentDiffAtMostTwo(string s)
    {
        for (int i = 1; i < s.size(); i++)
            if (abs(s[i] - s[i - 1]) > 2)
                return false;
        return true;
    }
};
