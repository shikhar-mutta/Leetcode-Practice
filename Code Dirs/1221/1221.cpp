// Link: https://leetcode.com/problems/split-a-string-in-balanced-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int balancedStringSplit(string s)
    {
        int count = 0, balance = 0;
        for (char c : s)
        {
            if (c == 'L')
                balance++;
            else
                balance--;
            if (balance == 0)
                count++;
        }
        return count;
    }
};
