// Link: https://leetcode.com/problems/keyboard-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSameRow(string &s)
    {
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        int count1 = 0, count2 = 0, count3 = 0;
        for (char c : s)
        {
            // Check for Substring presence in each row
            if (row1.find(c) != string::npos)
                count1++;
            else if (row2.find(c) != string::npos)
                count2++;
            else if (row3.find(c) != string::npos)
                count3++;
            // Early return if more than one row is used.
            if ((count1 > 0) + (count2 > 0) + (count3 > 0) > 1)
                return false;
        }
        return true;
    }
    vector<string> findWords(vector<string> &words)
    {
        vector<string> result;
        for (string &word : words)
        {
            if (isSameRow(word))
                result.push_back(word);
        }
        return result;
    }
};
