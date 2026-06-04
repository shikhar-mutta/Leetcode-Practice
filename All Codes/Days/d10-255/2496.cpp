// Link: https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: Iter Arr. TC: O(n*m), where m is the average length of strings. SC: O(1)
    int maximumValue(vector<string> &strs)
    {
        int maxVal = 0;
        for (const string &s : strs)
        {
            bool isNumber = true; // assume it's a number until we find a non-digit character
            for (char c : s)
                if (!isdigit(c))
                { // if we find a non-digit character, it's not a number
                    isNumber = false;
                    break;
                }
            // if it's a number, convert it to an integer and compare with maxVal
            if (isNumber)
                maxVal = max(maxVal, stoi(s));
            else
                maxVal = max(maxVal, (int)s.length());
        }
        return maxVal;
    }
};
